#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include "Level.h"
#include "menu.h"
#include <conio.h>

using namespace std;
class Game {
private:
	Player * player;
	vector<Level> levelList;
	int level;
	int mode;
	bool ONSOUND;
public:
	Game(Player * player, vector<Level> levelList, int level = 0, int mode = 1): player(player), levelList(levelList), level(level), ONSOUND(true), mode(mode){}
	void playing();
	void drawLevel();

};

#endif