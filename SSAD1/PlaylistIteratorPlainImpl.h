#pragma once
#include "PlaylistIteratorImpl.h"
#include "Track.h"
#include "TrackList.h"

class PlaylistIteratorPlainImpl :
	public PlaylistIteratorImpl
{
public:
	PlaylistIteratorPlainImpl(PlaylistIteratorImpl*);
	PlaylistIteratorPlainImpl(TrackList&);
	virtual ~PlaylistIteratorPlainImpl();

	Track& Next();
	Track& Prev();
};

