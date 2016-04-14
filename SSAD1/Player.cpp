#include "Player.h"
#include "PlaylistIteratorPlainImpl.h"

Player::Player(Playlist& playlist)
: playlist(playlist), playlistIterator(playlist, new PlaylistIteratorPlainImpl(playlist.GetContent()))
{
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
	music.openFromFile(((Track) playlistIterator.Next().Get()).filename);
}

void Player::Prev()
{
	music.openFromFile(((Track) playlistIterator.Prev().Get()).filename);
}

void Player::Stop()
{
	music.stop();
}

void Player::SetShuffle(bool shuffle)
{
	/// TODO
}
