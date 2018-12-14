#pragma once
#ifndef _file_h_
#define _file_h_
#include "Level.h"
#include <fstream>

using namespace std;
/*
game.dat structure:
4 bytes: number of level

	{
	4 bytes: number of lane
		{
		4 bytes: direction 
		4 bytes: speed
		4 bytes: hasTrafficlight
			4 bytes: time trafficlight
		4 bytes: number of objects
			per object
			4 bytes: type
			4 bytes: position
		}
	}
*/
/*
	save file
	4 bytes: number of players
	{
		4 bytes: highest level
		4 bytes: name length: n
		n bytes: player's name
	}
*/

class File {
public:
	int saveFile(vector<Player> player);
	int readFile(vector<Player> &player);
	int createDate();
	int readData(vector<Level> &levelList, vector<TrafficLight*> &trafficLight);
};
#endif 
