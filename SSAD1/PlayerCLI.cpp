#include "PlayerCLI.h"
#include <iostream>
#include <string>

PlayerCLI::PlayerCLI(Player& player)
: player(player)
{
}


PlayerCLI::~PlayerCLI()
{
}

void PlayerCLI::Run()
{
	while (true)
	{
		std::string command;
		std::getline(std::cin, command);
		if (command == "play")
		{
			player.Play();
		}
		else if (command == "pause")
		{
			player.Pause();
		}
		else if (command == "stop")
		{
			player.Stop();
		}
		else if (command == "next")
		{
			player.Next();
		}
		else if (command == "prev")
		{
			player.Prev();
		}
		else if (command == "shuffle on")
		{
			player.SetShuffle(true);
		}
		else if (command == "shuffle off")
		{
			player.SetShuffle(false);
		}
		else if (command == "list")
		{
			std::vector<Playable*> list = ((TrackList*)player.playlist.GetContent().GetContent()[0])->GetContent();
			for (auto& playable : list)
			{
				printList(0, playable);
			}
		}
		else
		{
			std::cout << "Unknown command; ignored." << std::endl;
		}
	}
}

void PlayerCLI::printList(int offset, const Playable* p)
{
	if (p->isFinite()) {
		std::cout << std::string(offset, ' ') << (&player.playlistIterator.Get() == p ? '>' : '|') << ' ' 
			<< p->getName() << std::endl;
	} else {
		std::cout << std::string(offset, ' ') << "|+ " << p->getName() << std::endl;
		for (auto& playable : ((TrackList*)p)->GetContent())
		{
			printList(offset + 1, playable);
		}
	}
}