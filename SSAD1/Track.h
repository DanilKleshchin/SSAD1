#pragma once
#include "Playable.h"
#include <iostream>
class Track :
	public Playable
{
public:
	Track(const std::string& path);
	virtual ~Track();

	bool isFinite() { return true; }
	std::string filename;
};

