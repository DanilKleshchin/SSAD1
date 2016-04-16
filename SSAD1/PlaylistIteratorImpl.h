#pragma once
#include "Track.h"
#include "TrackListPosition.h"
#include <iostream>
#include <stack>

class PlaylistIteratorImpl
{
public:
	PlaylistIteratorImpl();
	PlaylistIteratorImpl(TrackList& t);
	virtual ~PlaylistIteratorImpl();

	virtual Track& Next() = 0;
	virtual Track& Prev() = 0;
	void InitStack(TrackList& t);
	void InitStack(std::stack<TrackListPosition>& s);

	std::stack<TrackListPosition> stack;
	
};

