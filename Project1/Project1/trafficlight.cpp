#include "HeaderFile/trafficlight.h"

void TrafficLight::runTrafficLight() {
	while(!stop) {
		isRed = false;
		Sleep(greenTime*(!stop));
		isRed = true;
		Sleep(redTime*(!stop));
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