#pragma once
#include "PlaylistIteratorImpl.h"
#include "Track.h"
class Playlist;

class PlaylistIterator
{
public:
	PlaylistIterator(PlaylistIteratorImpl* impl);
	PlaylistIterator(Playlist& playlist, PlaylistIteratorImpl* impl);
	~PlaylistIterator();

	Track& Get();
	PlaylistIterator& Next();
	PlaylistIterator& Prev();
	void SetImpl(PlaylistIteratorImpl* i);

private:
	Playlist* playlist;
	PlaylistIteratorImpl* impl;
	Track* track;
};
