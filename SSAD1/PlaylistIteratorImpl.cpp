#include "PlaylistIteratorImpl.h"

PlaylistIteratorImpl::PlaylistIteratorImpl()
{
}

PlaylistIteratorImpl::PlaylistIteratorImpl(TrackList& t)
{
	InitStack(t);
}

PlaylistIteratorImpl::~PlaylistIteratorImpl()
{
}

void PlaylistIteratorImpl::InitStack(std::stack<TrackListPosition>& s)
{
	stack = s;
}

void PlaylistIteratorImpl::InitStack(TrackList& t)
{
	stack.push(TrackListPosition(&t, -1));
}
