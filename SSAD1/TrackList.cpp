#include <boost/filesystem.hpp>
#include "TrackList.h"
#include "Track.h"

/**
 * Load path as tracklist.
 */
TrackList::TrackList(const char* path)
{
	namespace fs = boost::filesystem;
	fs::path dir(path);
	name = dir.filename().string();
	if (fs::is_directory(dir)) {
		fs::directory_iterator end_iter;
		for (fs::directory_iterator dir_iter(dir) ; dir_iter != end_iter ; ++dir_iter)
		{
			std::string p = dir_iter->path().string();
			if (fs::is_regular_file(dir_iter->status()))
			{
				list.push_back(new Track( p ));
			}
			if (fs::is_directory(dir_iter->status()))
			{
				list.push_back(new TrackList( p.c_str() ));
			}
		}
	}
}

TrackList::TrackList()
{
}


TrackList::~TrackList()
{
	for (Playable* p : list)
		delete p;
}

const std::vector<Playable*> TrackList::GetContent()
{
	return list;
}

void TrackList::Append(Playable *playable)
{
	list.push_back(playable);
}
