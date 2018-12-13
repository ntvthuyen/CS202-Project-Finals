#include "HeaderFile/Level.h"
/*
void Level::Update(Player * player, int i, bool *isImpact) {
	*isImpact = false;
	if (lane[i]->hasTrafficLight()) {
		thread th(&TrafficLight::runTrafficLight, lane[i]->getTrafficLight());
		while (!STOP) {
			if (lane[i]->PlayerIsHere())
				if (!lane[i]->getTrafficLight()->IsRed())
					*isImpact = lane[i]->Update(0);
				else *isImpact = lane[i]->Update(1);
			else {
				if (!lane[i]->getTrafficLight()->IsRed())
					lane[i]->Update();
			}
			mtx.lock();
			drawObject(i);
			lane[player->getLane()]->drawPlayer();
			mtx.unlock();
			Sleep(lane[i]->getSpeed());
			if (*isImpact) {
				lane[i]->getTrafficLight()->Stop();
				th.join();
				return;
			}
		}		
		lane[i]->getTrafficLight()->Stop();
		th.join();
	}
	else {
		while (!STOP) {
			if (lane[i]->PlayerIsHere())
					*isImpact = lane[i]->Update(0);
			else {
					lane[i]->Update();
			}
			mtx.lock();
			drawObject(i);
			lane[player->getLane()]->drawPlayer();
			mtx.unlock();
			Sleep(lane[i]->getSpeed());
			if (*isImpact) {
				return;
			}
		}
	}
}*/
size_t Level::size() {
	return lane.size();
}/*
void Level::drawObject(int i) {
		int row = (i)*9 + 1;
		lane[i]->drawLane(row);
}*/
void Level::drawLine() {
	Draw a;
	mtx.lock();
	a.cursorPosition(0, 0);
	a.setTextColor(19);
	for (int i = 0; i < lane.size(); ++i) {
		cout << "\n\n\n\n\n\n\n\n\n";
		//cout << "-----------------------------------------------------------------------------------------------------";
		//cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		cout << "#####################################################################################################";
	}
	mtx.unlock();
}
void Level::goNextLane(int cl, Player * player) {
	lane[cl]->playerOut();
	lane[cl - 1]->playerIn(player);
}
void Level::goToLane(int cl, Player * player) {
	lane[cl]->playerIn(player);
}
void Level::reset() {
	for (int i = 0; i < lane.size(); i++) {
		lane[i]->playerOut();
	}
}

void Level::Stop() {
	//STOP = true;
	for (int i = 0; i < size(); i++) {
		lane[i]->Stop();
	}
}
void Level::Run() {
	//STOP = true;
	for (int i = 0; i < size(); i++) {
		lane[i]->Run();
	}
}
void Level::setLaneNumber() {
	//STOP = true;
	for (int i = 0; i < size(); i++) {
		lane[i]->setLaneNumber(i);
	}
}
Lane * Level::getLane(int i) {
	if (i < lane.size()) {
		Lane * temp;
		temp = lane[i];
		return temp;
	}
}