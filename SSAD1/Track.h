#pragma once
#include "Playable.h"
#include <iostream>
class Track :
	public Playable
{
public:
	Track();
	virtual ~Track();
private:
	std::string filename;
};

