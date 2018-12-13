#ifndef _Lane_H_
#define _Lane_H_

#include <vector>
#include "object.h"
#include "trafficlight.h"
using namespace std;

class Lane{
private:
	Player * player;
	vector<mObject*> obj;
	Direction direct;
	int speed;
	TrafficLight * trafficLight;
public:
	Lane(vector<mObject*> obj, Direction direct, int speed, Player * player = NULL, TrafficLight * trafficLight = NULL) : direct(direct), obj(obj), player(player), speed(speed), trafficLight(trafficLight){}
	void playerIn(Player * &player);
	void playerOut();
	void drawPlayer();
	void drawLane(int row);
	void Update();
	bool isImpact(Player &player) const;
	bool PlayerIsHere();
	bool Update(int t);
	bool hasTrafficLight();
	int getSpeed();
	TrafficLight *getTrafficLight();
	~Lane(){
	}
};

#endif