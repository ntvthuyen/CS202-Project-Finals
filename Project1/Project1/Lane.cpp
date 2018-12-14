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
	if (hasTrafficLight()) {
		if (direct == LEFT)
			v.drawTrafficLight(1, row, trafficLight->IsRed());
		else
			v.drawTrafficLight(96, row, trafficLight->IsRed());
	}
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
bool Lane::hasTrafficLight() {
	if (trafficLight != NULL) return true;
	return false;
}
TrafficLight * Lane::getTrafficLight() {
	return trafficLight;
}
void Lane::_Update(bool *isImpact, int *mode) {
	*isImpact = false;
	if (hasTrafficLight()) {
		th = new thread(&TrafficLight::runTrafficLight, getTrafficLight());
		while (!stop) {
			if (PlayerIsHere())
				if (!getTrafficLight()->IsRed())
					*isImpact = Update(0);
				else *isImpact = Update(1);
			else {
				if (!getTrafficLight()->IsRed())
					Update();
			}
			mtx.lock();
			drawObject();
			if(PlayerIsHere()) drawPlayer();
			mtx.unlock();
			Sleep(getSpeed() - 25*(*mode));
			if (*isImpact) {
				trafficLight->Stop();
				//th->detach();
				if (th->joinable())th->join();
				if (PlayerIsHere()) {
					Draw a;
					a.deleteHuman(player->getPosition(), (player->getLane() + 1) * 9 + 7);
				}
				return;
			}
		}
		trafficLight->Stop();
		//th->detach();
		if(th->joinable())th->join();
	}
	else {
		while (!stop) {
			if (PlayerIsHere())
				*isImpact = Update(0);
			else {
				Update();
			}
			mtx.lock();
			drawObject();
			if (PlayerIsHere()) drawPlayer();
			mtx.unlock();
			Sleep(getSpeed() - 25*(*mode));
			if (*isImpact) {
				if (PlayerIsHere()) {
					Draw a;
					a.deleteHuman(player->getPosition(), (player->getLane() + 1) * 9 + 7);
				}
				return;
			}
		}
	}
}
void Lane::drawObject() {
	int row = lane * 9 + 1;
	drawLane(row);
}
void Lane::Run() {
	if (trafficLight)trafficLight->Run();
	stop = false;
}
void Lane::Stop() {
	if (trafficLight)trafficLight->Stop();
	stop = true;
}	
void Lane::setLaneNumber(int i) {
	lane = i;
};
