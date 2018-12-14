#pragma once
#ifndef _Level_h
#define _Level_h
#include "lane.h"
#include <iostream>
#include "Header.h"

class Level {
private:
	vector<Lane*> lane;
	bool STOP;
public:
	Level(vector<Lane*> lane) : lane(lane),STOP(false){}
	size_t size();
	void reset();
	void goNextLane(int cl, Player * player);
	void goToLane(int cl, Player * player);
	void Update(Player * player,int i, bool *isImpact);
	void drawLine();
	void setLaneNumber();
	void drawObject(int i);
	void Run();
	void Stop();
	Lane * getLane(int i);
};
#endif