#pragma once
class Player
{
public:	
	Player();
	~Player();

	void Play();
	void Pause();
	void Next();
	void Prev();
	void Stop();
	void SetShuffle(bool shuffle);
};

