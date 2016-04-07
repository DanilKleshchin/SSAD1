#include "PlaylistIteratorPlainlmpl.h"



PlaylistIteratorPlainlmpl::PlaylistIteratorPlainlmpl(PlaylistIteratorlmpl)
{
}

PlaylistIteratorPlainlmpl::PlaylistIteratorPlainlmpl(TrackList)
{
}

PlaylistIteratorPlainlmpl::PlaylistIteratorPlainlmpl()
{
}


PlaylistIteratorPlainlmpl::~PlaylistIteratorPlainlmpl()
{
}

Track PlaylistIteratorPlainlmpl::Next()
{
	return Track();
}

Track PlaylistIteratorPlainlmpl::Prev()
{
	return Track();
}
