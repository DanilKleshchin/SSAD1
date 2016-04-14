#include "PlaylistIteratorImpl.h"



PlaylistIteratorImpl::PlaylistIteratorImpl(TrackListPosition& p)
{
	stack.push(p);
}

PlaylistIteratorImpl::PlaylistIteratorImpl(std::stack<TrackListPosition> s)
: stack(s)
{
}

PlaylistIteratorImpl::~PlaylistIteratorImpl()
{
}
