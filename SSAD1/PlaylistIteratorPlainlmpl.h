#pragma once
#include "PlaylistIteratorlmpl.h"
#include "Track.h"
#include "TrackList.h"

class PlaylistIteratorPlainlmpl :
	public PlaylistIteratorlmpl
{
public:
	PlaylistIteratorPlainlmpl(PlaylistIteratorlmpl);
	PlaylistIteratorPlainlmpl(TrackList);
	PlaylistIteratorPlainlmpl();
	virtual ~PlaylistIteratorPlainlmpl();

	Track Next();
	Track Prev();
};

