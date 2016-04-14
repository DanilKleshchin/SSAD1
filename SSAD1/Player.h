#pragma once
#include <SFML/Audio/Music.hpp>
#include "Playlist.h"
#include "PlaylistIterator.h"

class Player
{
public:	
	Player(Playlist& playlist);
	~Player();

	void Play();
	void Pause();
	void Next();
	void Prev();
	void Stop();
	void SetShuffle(bool shuffle);

	Playlist& playlist;
	PlaylistIterator playlistIterator;
	sf::Music music;
};

