#include "HeaderFile/lane.h"


void Lane::Update() {
	for (int i = 0; i < obj.size(); i++) {
		if (direct) obj[i]->moveRight();
		else obj[i]->moveLeft();
	}
}
bool Lane::Update(int) {
	for (int i = 0; i < obj.size(); i++) {
		if (direct) obj[i]->moveRight();
		else obj[i]->moveLeft();
	}
	if (player) {
		return isImpact(*player);
	}
	return false;
}
void Lane::drawLane(int row){
	View v;
	v.cursorPosition(0, row);
	v.setTextColor(15);
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
bool Lane::hasATrafficLight() {
	return hasTrafficLight;
}