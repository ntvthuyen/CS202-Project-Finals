#ifndef _Lane_H_
#define _Lane_H_

#include <vector>
#include "object.h"

using namespace std;

class Lane{
private:
	Player * player;
	vector<mObject*> obj;
	Direction direct;
	int speed;
	bool hasTrafficLight;
public:
	Lane(vector<mObject*> obj, Direction direct, int speed, Player * player = NULL, bool hasTrafficLight = false) : direct(direct), obj(obj), player(player), speed(speed), hasTrafficLight(hasTrafficLight){}
	void playerIn(Player * &player);
	void playerOut();
	void drawPlayer();
	void drawLane(int row);
	void Update();
	bool isImpact(Player &player) const;
	bool PlayerIsHere();
	bool Update(int);
	bool hasATrafficLight();
	int getSpeed();
	~Lane(){
	}
};

#endif