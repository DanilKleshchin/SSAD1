#pragma once
#include "TrackList.h"
#include "PlaylistIterator.h"

class Playlist
{
public:
	Playlist();
	~Playlist();

	TrackList& GetContent();
	void SetContent(TrackList& content);
	PlaylistIterator Iterate();

private:
	TrackList content;
};