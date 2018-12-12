#pragma once
#ifndef _Level_h
#define _Level_h
#include "lane.h"
#include <iostream>
#include <mutex>

extern std::mutex mtx;

class Level {
private:
	vector<Lane*> lane;
public:
	Level(vector<Lane*> lane) : lane(lane){}
	size_t size();
	void reset();
	void goNextLane(int cl, Player * player);
	void goToLane(int cl, Player * player);
	void Update(Player * player,int i, bool *isImpact);
	void drawHuman(Player * player);
	void drawLine();
	void drawObject(int i);
};

#endif