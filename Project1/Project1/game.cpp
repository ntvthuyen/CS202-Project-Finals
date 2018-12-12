#include "HeaderFile/game.h"
mutex mtx;
void Game::playing(int level){
	Draw a;
	if (levelList[level].size() == 7) {
		//a.changeFontSize(12);
	}
	//fontSize(levelList[level].size());
	system("cls");
	system("color 07");
	player->resetPosition();
	player->setLane(levelList[level].size() - 1);
	levelList[level].goToLane(levelList[level].size() - 1, player);
	a.cursorPosition(0, 0);
	a.setTextColor(YELLOW);
	cout << "@@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@N@WIN@WIN@WIN@WIN@WIN@@";
	levelList[level].drawLine();
	vector<thread*> th;
	bool isImpact=false;
	for (int i = 0; i < levelList[level].size(); i++) {
		th.push_back(new thread(&Level::Update, levelList[level], player, i, &isImpact));
	}
	int z;
	while (true) {
		if (isImpact) {
			system("color 70");
			for (int i = 0; i < levelList[level].size(); i++) {
				th[i]->join();
				int choice = a.drawNotification(40, 20, "YOU LOSE! Wanna try again?!", 242, 249, true);
				if (choice == 0) exit(0);
				else{
					levelList[level].reset();
					playing(level);
				}
			}
		} else 
		z = _getch(); 
		if (z == 27) {
			mtx.lock();
			a.drawFrame(40, 17, WHITE);
			vector<string> item;
			item.push_back("          Resume");
			item.push_back("          Save game");
			item.push_back("          Exit");
			Menu menu(item,42,19,WHITE,BLUE);
			int temp = menu.runMenu();
			switch (temp) {
			case 1: {

			}
			case 2: {
				mtx.unlock();
				exit(0);
			}
			}
			mtx.unlock();
			levelList[level].drawLine();
		}
		else if (z == 'a') {
			mtx.lock();
			player->moveLeft();
			mtx.unlock();

		}
		else if (z == 'w') {
			if (player->getLane() != 0) {
				levelList[level].goNextLane(player->getLane(), player);
				mtx.lock();
				(player)->moveForward();
				mtx.unlock();
			}
		}
		else if (z == 'd') {
			mtx.lock();
			player->moveRight();
			mtx.unlock();
		}

	}
}