#include "Player.h"
#include "PlaylistIteratorPlainImpl.h"
#include "PlaylistIteratorShuffleImpl.h"

Player::Player(Playlist& playlist)
: playlist(playlist), playlistIterator(playlist, new PlaylistIteratorPlainImpl(playlist.GetContent()))
{
	music.openFromFile(((Track) playlistIterator.Get()).filename);
}

Player::~Player()
{
}

void Player::Play()
{
	music.play();
}

void Player::Pause()
{
	music.pause();
}

void Player::Next()
{
	sf::Music::Status s = music.getStatus();
	music.openFromFile(((Track)playlistIterator.Next().Get()).filename);
	if (s == sf::Music::Status::Playing)
	{
		music.play();
	}
}

void Player::Prev()
{
	sf::Music::Status s = music.getStatus();
	music.openFromFile(((Track)playlistIterator.Prev().Get()).filename);
	if (s == sf::Music::Status::Playing)
	{
		music.play();
	}
}

void Player::Stop()
{
	music.stop();
}

void Player::SetShuffle(bool shuffle)
{
	playlistIterator.SetImpl(shuffle
		? (PlaylistIteratorImpl*) new PlaylistIteratorShuffleImpl()
		: (PlaylistIteratorImpl*) new PlaylistIteratorPlainImpl()
		);
}
