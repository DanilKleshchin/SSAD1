#pragma once
#include "Player.h"

class PlayerCLI
{
public:
	PlayerCLI(Player& player);
	~PlayerCLI();
	void Run();
private:
	Player& player;
	void printList(int offset, const Playable* p);
};

