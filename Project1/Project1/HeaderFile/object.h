#ifndef _object_h_
#define _object_h_


#include <iostream>
#include <string>
#include "UI.h"

using namespace std;

class Object {
private:
	int w; 
protected:
	int position;
public:
	Object(int position = 0, int w = 0) : position(position), w(w){};
	virtual void moveLeft();
	virtual void moveRight();
	void resetPosition();
	int getPosition();
	int getW();
	virtual void draw(int row) = 0;
};
class mObject : public Object {
protected:
	Direction direct;
public:
	mObject() = default;
	mObject(Direction direct, int position = 0,int w = 0) : Object(position, w),direct(direct){}
	virtual void draw(int row) = 0;
	void moveLeft();
	void moveRight();
};
class Truck : public mObject {
public:
	Truck(Direction direct, int position = 0, int w = 6) : mObject(direct , position, w){}
	void draw(int row);
};
class Car : public mObject {
public:
	Car(Direction direct, int position = 0, int w = 4) : mObject(direct, position, w) {}
	void draw(int row);
};
class Bird : public mObject {
public:
	Bird(Direction direct, int position = 0, int w = 3) : mObject(direct, position, w) {}
	void draw(int row);
};
class Dino : public mObject {
public:
	Dino(Direction direct, int position = 0, int w = 5) : mObject(direct, position, w) {}
	void draw(int row);
};

class Player : public Object {
private:
	string pName;
	int lane;
	int highestlevel;
public:
	Player(string pName, int position = 0, int highestlevel = 0) : Object(position, 1), pName(pName),highestlevel(highestlevel) {}
	int getLane();
	int getHigestLevel();
	string getName();
	void moveForward();
	void draw(int row);
	bool isImpact(mObject &obj);
	void setLane(int lane);
	void record(int level);
	void drawEffect(int row);
	void drawInfo(int column, int row, Color color1 = YELLOW , Color = BLUE);
};

#endif