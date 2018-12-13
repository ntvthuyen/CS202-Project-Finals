#include "HeaderFile/lane.h"


void Lane::Update() {
	for (int i = 0; i < obj.size(); i++) {
		if (direct) obj[i]->moveRight();
		else obj[i]->moveLeft();
	}
}
bool Lane::Update(int t) {
	if (t == 0) {
		for (int i = 0; i < obj.size(); i++) {
			if (direct) obj[i]->moveRight();
			else obj[i]->moveLeft();
		}
	}
	if (player) {
		return isImpact(*player);
	}
	return false;
}
void Lane::drawLane(int row){
	Draw v;
	v.setTextColor(15);
	
	v.cursorPosition(0, row);
	cout<< "#                                                                                                   #" << endl
		<< "#                                                                                                   #" << endl
		<< "#                                                                                                   #" << endl
		<< "#                                                                                                   #" << endl
		<< "#                                                                                                   #" << endl
		<< "#                                                                                                   #" << endl
		<< "#                                                                                                   #" << endl
		<< "#                                                                                                   #" << endl;
		for (int i = 0; i < obj.size(); i++) {
			obj[i]->draw(row + 3);
		}
		if (hasTrafficLight()) {
			if (direct == LEFT)
				v.drawTrafficLight(1, row, trafficLight->IsRed());
			else
				v.drawTrafficLight(96, row, trafficLight->IsRed());
		}
}
bool Lane::isImpact(Player &player) const{
	for(int i = 0; i < obj.size();i++)	
		if(player.isImpact(*obj[i])) return true;
	return false;
}
int Lane::getSpeed() {
	return speed;
}
bool Lane::PlayerIsHere() {
	if (player) return true;
	return false;
}
void Lane::playerIn(Player * &player) {
	this->player = player;
}
void Lane::playerOut() {
	player = NULL;
}
void Lane::drawPlayer() {
	if (player) {
		player->draw(player->getLane() * 9 + 4);
		//			cout << player->getPosition();
	}
}
bool Lane::hasTrafficLight() {
	if (trafficLight != NULL) return true;
	return false;
}
TrafficLight * Lane::getTrafficLight() {
	return trafficLight;
}