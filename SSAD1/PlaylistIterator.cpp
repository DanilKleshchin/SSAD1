#include "PlaylistIterator.h"
#include "Playlist.h"
#include "PlaylistIteratorImpl.h"

PlaylistIterator::PlaylistIterator(Playlist& playlist, PlaylistIteratorImpl* impl)
: playlist(&playlist), impl(impl), track(&impl->Next())
{
}

PlaylistIterator::~PlaylistIterator()
{
	delete impl;
}

Track& PlaylistIterator::Get()
{
	return *track;
}

PlaylistIterator& PlaylistIterator::Next()
{
	track = &impl->Next();
	return *this;
}

PlaylistIterator& PlaylistIterator::Prev()
{
	track = &impl->Prev();
	return *this;
}

void PlaylistIterator::SetImpl(PlaylistIteratorImpl *i)
{
	i->InitStack(impl->stack);
	delete impl;
	impl = i;
}
