#ifndef _object_h_
#define _object_h_


#include <iostream>
#include <string>
#include "UI.h"

using namespace std;

class Object {
private:
	int w; // w h = real w h / 2
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
	//virtual void drawBlank() = 0;
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
public:
	Player(string pName, int position = 0, int w = 1) : Object(position, w) {}
	void moveForward();
	void draw(int row);
	bool isImpact(mObject &obj);
	void setLane(int lane);
	int getLane();
};

#endif