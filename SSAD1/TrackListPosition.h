#pragma once
#include <iostream>
#include "TrackList.h"

class TrackListPosition
{
public:
	TrackListPosition(TrackList* list, int p);
	~TrackListPosition();

	TrackList* tracklist;
	std::size_t position;
};

