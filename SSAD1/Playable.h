#pragma once
class Playable
{
public:
	Playable();
	virtual ~Playable();
	
	virtual bool isFinite() = 0;

};

