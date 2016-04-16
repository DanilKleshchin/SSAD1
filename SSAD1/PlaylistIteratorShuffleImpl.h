#pragma once
#include <random>
#include "PlaylistIteratorImpl.h"
#include "TrackList.h"

class PlaylistIteratorShuffleImpl :
	public PlaylistIteratorImpl
{
public:
	PlaylistIteratorShuffleImpl();
	PlaylistIteratorShuffleImpl(TrackList& t);
	virtual ~PlaylistIteratorShuffleImpl();

	Track& Next();
	Track& Prev();
private:
	static std::random_device rdev;
	std::uniform_int_distribution<int> randomize;
};

