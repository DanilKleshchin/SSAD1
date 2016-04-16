#pragma once
#include <string>

class Playable
{
public:
	Playable();
	virtual ~Playable();
	
	virtual std::string getName() const = 0;
	virtual bool isFinite() const = 0;

};

