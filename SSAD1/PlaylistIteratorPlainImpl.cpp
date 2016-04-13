#include "PlaylistIteratorPlainImpl.h"



PlaylistIteratorPlainImpl::PlaylistIteratorPlainImpl(PlaylistIteratorImpl* impl)
: PlaylistIteratorImpl(impl->stack)
{
	delete impl;
}

PlaylistIteratorPlainImpl::PlaylistIteratorPlainImpl(TrackList& list)
: PlaylistIteratorImpl(TrackListPosition(&list, 0))
{
	stack.push(TrackListPosition(&list, 0));
}

PlaylistIteratorPlainImpl::~PlaylistIteratorPlainImpl()
{
}

Track& PlaylistIteratorPlainImpl::Next()
{
	Playable* p;
	do {
		stack.top().position++;
		if (stack.top().tracklist->GetContent().size() == stack.top().position) {
			stack.pop();
		}
		p = stack.top().tracklist->GetContent()[stack.top().position];
		if (!p->isFinite()) {
			stack.push(TrackListPosition((TrackList*)p, 0));
		}
	} while (!p->isFinite());
	return *(Track*)p;
}

Track& PlaylistIteratorPlainImpl::Prev()
{
	Playable* p;
	do {
		stack.top().position--;
		if (stack.top().tracklist->GetContent().size() == -1) {
			stack.pop();
			stack.top().position--;
		}
		p = stack.top().tracklist->GetContent()[stack.top().position];
		if (!p->isFinite()) {
			stack.push(TrackListPosition((TrackList*)p, 0));
		}
	} while (!p->isFinite());
	return *(Track*)p;
}
