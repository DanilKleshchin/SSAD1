#pragma once
#include "Track.h"
#include "TrackListPosition.h"
#include <iostream>
#include <stack>

class PlaylistIteratorlmpl
{
public:
	PlaylistIteratorlmpl();
	virtual ~PlaylistIteratorlmpl();

	Track Next();
	Track Prev();

	std::stack<TrackListPosition> stack;
	
};

