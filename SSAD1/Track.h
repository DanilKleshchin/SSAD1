#pragma once
#include "Playable.h"
#include <iostream>

class Track :
	public Playable
{
public:
	Track(const std::string& path);
	virtual ~Track();

	std::string getName() const { return name; };
	bool isFinite() const { return true; }
	std::string name, filename;
};

