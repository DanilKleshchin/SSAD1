#pragma once
#include <vector>
#include "Playable.h"
class TrackList :
	public Playable
{
public:
	TrackList(const char* path);
	TrackList();
	virtual ~TrackList();

	void Append(Playable *playable);
	const std::vector<Playable*> GetContent();
	std::string getName() const { return name; };
	bool isFinite() const { return false; }
private:
	std::string name;
	std::vector<Playable*> list;
};

