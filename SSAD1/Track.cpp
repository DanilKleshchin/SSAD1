#include "Track.h"
#include "boost/filesystem.hpp"

Track::Track(const std::string& path) : filename(path)
{
	name = boost::filesystem::path(path).filename().string();
}

Track::~Track()
{
}
