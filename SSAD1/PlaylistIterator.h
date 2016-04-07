#pragma once
#include "PlaylistIteratorlmpl.h"
#include "Track.h"

class PlaylistIterator
{
public:
	PlaylistIterator(PlaylistIteratorlmpl impl);
	PlaylistIterator();
	~PlaylistIterator();

	Track Get();
	PlaylistIterator Next();
	PlaylistIterator Prev();
	void Setlmpl(PlaylistIteratorlmpl lmpl);
};

