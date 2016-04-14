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
	bool isFinite() { return false; }
private:
	std::vector<Playable*> list;
};

