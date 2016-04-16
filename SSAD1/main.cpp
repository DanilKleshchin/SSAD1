#include <boost/filesystem.hpp>
#include <iostream>
#include "Player.h"
#include "PlayerCLI.h"
#include "Playlist.h"
#include "TrackList.h"

int main(int argc, char *argv[])
{
	Playlist playlist;
	if (argc == 2 && boost::filesystem::is_directory(boost::filesystem::path(argv[1])))
	{
		playlist.GetContent().Append(new TrackList(argv[1]));
	}
	Player player(playlist);
	PlayerCLI cli(player);
	cli.Run();
	return 0;
}