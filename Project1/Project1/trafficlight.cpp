#include "HeaderFile/trafficlight.h"

void TrafficLight::runTrafficLight() {
	while(!stop) {
		isRed = false;
		Sleep(greenTime);
		isRed = true;
		Sleep(redTime);
	}
}
bool TrafficLight::IsRed() {
	return isRed;
}
void TrafficLight::Stop() {
	stop = true;
}
void TrafficLight::Run() {
	stop = false;
}