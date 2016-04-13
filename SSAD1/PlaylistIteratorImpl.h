#pragma once
#include "Track.h"
#include "TrackListPosition.h"
#include <iostream>
#include <stack>

class PlaylistIteratorImpl
{
public:
	PlaylistIteratorImpl(TrackListPosition& p);
	PlaylistIteratorImpl(std::stack<TrackListPosition> s);
	virtual ~PlaylistIteratorImpl();

	virtual Track& Next() = 0;
	virtual Track& Prev() = 0;

	std::stack<TrackListPosition> stack;
	
};

