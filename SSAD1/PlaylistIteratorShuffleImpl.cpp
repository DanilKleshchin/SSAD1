#include "PlaylistIteratorShuffleImpl.h"

std::random_device PlaylistIteratorShuffleImpl::rdev;

PlaylistIteratorShuffleImpl::PlaylistIteratorShuffleImpl()
{
}

PlaylistIteratorShuffleImpl::PlaylistIteratorShuffleImpl(TrackList& t)
: PlaylistIteratorImpl(t)
{
}

PlaylistIteratorShuffleImpl::~PlaylistIteratorShuffleImpl()
{
}

Track& PlaylistIteratorShuffleImpl::Next()
{
	Playable* p;
	do {
		stack.top().position = randomize(rdev) % stack.top().tracklist->GetContent().size();
		p = stack.top().tracklist->GetContent()[stack.top().position];
		if (!p->isFinite()) {
			stack.push(TrackListPosition((TrackList*) p, 0));
			randomize = std::uniform_int_distribution<int>(0, stack.top().tracklist->GetContent().size() - 1);
		}
	} while (!p->isFinite());
	return * (Track*)p;
}

Track& PlaylistIteratorShuffleImpl::Prev()
{
	return Next();
}
