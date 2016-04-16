#include "PlaylistIteratorPlainImpl.h"



PlaylistIteratorPlainImpl::PlaylistIteratorPlainImpl()
{
}

PlaylistIteratorPlainImpl::PlaylistIteratorPlainImpl(TrackList& t)
: PlaylistIteratorImpl(t)
{
}

PlaylistIteratorPlainImpl::~PlaylistIteratorPlainImpl()
{
}

Track& PlaylistIteratorPlainImpl::Next()
{
	Playable* p;
	do {
		stack.top().position++;
		while (stack.top().tracklist->GetContent().size() == stack.top().position) {
			if (stack.size() == 1)
			{
				stack.top().position = 0;
			}
			else
			{
				stack.pop();
				stack.top().position++;
			}
		}
		p = stack.top().tracklist->GetContent()[stack.top().position];
		if (!p->isFinite()) {
			stack.push(TrackListPosition((TrackList*)p, -1));
		}
	} while (!p->isFinite());
	return *(Track*)p;
}

Track& PlaylistIteratorPlainImpl::Prev()
{
	Playable* p;
	do {
		stack.top().position--;
		while (stack.top().position == -1) {
			if (stack.size() == 1)
			{
				stack.top().position = 0;
			}
			else
			{
				stack.pop();
				stack.top().position--;
			}
		}
		p = stack.top().tracklist->GetContent()[stack.top().position];
		if (!p->isFinite()) {
			stack.push(TrackListPosition((TrackList*)p, ((TrackList*)p)->GetContent().size()));
		}
	} while (!p->isFinite());
	return *(Track*)p;
}
