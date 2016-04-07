#pragma once
#include "PlaylistIteratorlmpl.h"
#include "TrackList.h"

class PlaylistIteratorShufflelmpl :
	public PlaylistIteratorlmpl
{
public:
	PlaylistIteratorShufflelmpl(PlaylistIteratorlmpl);
	PlaylistIteratorShufflelmpl(TrackList);
	PlaylistIteratorShufflelmpl();
	virtual ~PlaylistIteratorShufflelmpl();

	Track Next();
	Track Prev();
};

