#ifndef _Lane_H_
#define _Lane_H_

#include <vector>
#include "object.h"
#include "trafficlight.h"
#include "Header.h"

using namespace std;

class Lane{
private:
	Player * player;
	vector<mObject*> obj;
	Direction direct;
	int speed;
	TrafficLight * trafficLight;
	int lane;
	bool stop;
public:
	Lane(vector<mObject*> obj, Direction direct, int speed, Player * player = NULL, TrafficLight * trafficLight = NULL) : direct(direct), obj(obj), player(player), speed(speed), trafficLight(trafficLight), stop(false), lane(0){}
	void playerIn(Player * &player);
	void playerOut();
	void drawPlayer();
	void drawLane(int row);
	void setLaneNumber(int i);
	void Update();
	void _Update(bool *isImpact, int *mode);
	void drawObject();
	void Run();
	void Stop();
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