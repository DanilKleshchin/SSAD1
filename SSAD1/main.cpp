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
		Player player(playlist);
		PlayerCLI cli(player);
		cli.Run();
	}
	else
	{
		std::cout << "Still Silly Audio Directory player [SSAD1 Project] v1.0" << std::endl
			<< "Fork it at https://github.com/DanilSFEDU/SSAD1" << std::endl
			<< "Usage: " << argv[0] << " directory" << std::endl
			<< "Inner CLI commands: play, pause, stop, prev, next, shuffle on, shuffle off." << std::endl
			<< "Complete list of supported file formats are: ogg, wav, flac, aiff, au, raw, paf, svx, "
			"nist, voc, ircam, w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64." << std::endl
			<< "Based on SFML <sfml-dev.org> and Boost <boost.org> libraries." << std::endl
			<< "(c) 2016 Danil Kleschin, Edward Minasyan" << std::endl;
	}
	return 0;
}