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
public:
	Game(Player * player, vector<Level> levelList, int level = 0): player(player), levelList(levelList), level(level){}
	void playing();
	void drawLevel();
};

#endif