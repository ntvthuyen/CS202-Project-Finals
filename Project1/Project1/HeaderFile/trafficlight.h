#pragma once
#ifndef _TRAFFICLIGHT_H_
#define _TRAFFICLIGHT_H_

#include "UI.h"
#include <thread>
class TrafficLight {
private:
	bool isRed;
	int greenTime;
	int redTime;
	bool stop;
public:
	TrafficLight(bool isRed = false,int greenTime = 5000, int redTime = 3000):
		isRed(isRed), greenTime(greenTime), redTime(redTime), stop(false){}
	void runTrafficLight();
	bool IsRed();
	void Stop();
	void Run();
};

#endif