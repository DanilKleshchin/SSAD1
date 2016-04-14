#include "Playlist.h"
#include "PlaylistIteratorPlainImpl.h"



Playlist::Playlist()
{
}


Playlist::~Playlist()
{
}

TrackList& Playlist::GetContent()
{
	return content;
}

void Playlist::SetContent(TrackList& c)
{
	content = c;
}

PlaylistIterator Playlist::Iterate()
{
	return PlaylistIterator(*this, new PlaylistIteratorPlainImpl(GetContent()));
}
