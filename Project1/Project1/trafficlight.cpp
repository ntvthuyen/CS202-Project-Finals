#include "HeaderFile/trafficlight.h"

void TrafficLight::runTrafficLight() {
	while(true) {
		isRed = false;
		Sleep(greenTime);
		isRed = true;
		Sleep(redTime);
	}
}
bool TrafficLight::IsRed() {
	return isRed;
}