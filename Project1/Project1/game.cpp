#include "HeaderFile/game.h"
mutex mtx;
void Game::playing(vector<Player> &playerlist){
	Sound * sound;
	if (level > 5) {
		sound = new Sound("loop1.wav", "loop");
	}
	else
		sound = new Sound("loop2.wav", "loop");

	Sound victory("win.wav", "win");
	Sound jump("jump.wav", "jump");
	Sound crash("crash.wav");
	Draw a;
	if (levelList[level].size() == 7) {
		//a.changeFontSize(12);
	}
	//fontSize(levelList[level].size());
	system("cls");
	system("color 07");
	drawLevel();

	levelList[level].reset();
	player->resetPosition();
	levelList[level].setLaneNumber();
	levelList[level].Run();
	player->setLane(levelList[level].size() - 1);
	levelList[level].goToLane(levelList[level].size() - 1, player);
	a.cursorPosition(0, 0);
	a.setTextColor(YELLOW);
	cout << "@@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@WIN@N@WIN@WIN@WIN@WIN@WIN@@";
	levelList[level].drawLine();
	vector<thread> th;
	bool isImpact=false;
	for (int i = 0; i < levelList[level].size(); i++) {
		th.push_back(thread(&Lane::_Update, levelList[level].getLane(i), &isImpact, &mode));
	}
	//levelList[level].Stop();
	/*for (int i = 0; i < levelList[level].size(); i++) {
		th[i].join();
	}*/
	int z;
	while (true) {
		 z = _getch(); 
		if (z == 27) {
			mtx.lock();
			a.drawFrame(40, 17, WHITE);
			vector<string> item;
			item.push_back("          Resume");
			item.push_back("          Load game");
			item.push_back("          Save game");
			if(mode == 0)
				item.push_back("          Mode:EASY");
			else if (mode ==1 )
				item.push_back("          Mode:NORMAL");
			else
				item.push_back("          Mode:HARD");
			if(ONSOUND)
			item.push_back("          Sound:ON");
			else
			item.push_back("          Sound:OFF");
			item.push_back("          Exit");
			Menu menu(item,42,19,WHITE,BLUE);
			int temp = menu.runMenu();
			switch (temp) {
			case 1: {
				vector<string> m;
				for (int i = 0; i < playerlist.size(); i++) {
					m.push_back(playerlist[i].getName());
				}
				m.push_back("Back");
				Menu t(m, 49, 7);
				int x = t.runMenu();
				if (x == playerlist.size()) break;
				player = &playerlist[x];
				playing(playerlist);
			}
			case 2: {
				File file;
				file.saveFile(playerlist);
				break;
			}
			case 3: {
				mode = ++mode % 3;
				break;
			}
			case 4: {
				ONSOUND = !ONSOUND;
				if (ONSOUND) {
					sound->open();
					sound->play();
				}
				else sound->stop();
				break;
			}
			case 5: {
				mtx.unlock();
				levelList[level].Stop();
				for (int i = 0; i < levelList[level].size(); i++)
					if (th[i].joinable()) th[i].join();
				File file;
				file.saveFile(playerlist);
				exit(0);
			}
			}
			
			item.clear();
			mtx.unlock();
			levelList[level].Run();
			levelList[level].drawLine();
			drawLevel();
		}
		else if (z == 'a') {
			player->moveLeft();
		}
		else if (z == 'w' && !isImpact) {
			if (player->getLane() != 0) {
				if(ONSOUND)jump._play();
				levelList[level].goNextLane(player->getLane(), player);
				(player)->moveForward();
			}
			else {
				victory._play();
				system("color 61");
				player->record(level);
				levelList[level].Stop();
				for (int i = 0; i < levelList[level].size(); i++)
					if (th[i].joinable()) th[i].join();
				if (levelList.size() > level + 1) {
					int choice = a.drawNotification(40, 20, " YOU'VE PASS THIS LEVEL!", " Wanna try next one?", 1, 15, true);
					if (choice == 0) {
						a.drawNotification(40, 20, " BYE!! See ya!!", " Press any key to exit!", 1, 15, true);
						File file;
						file.saveFile(playerlist);
						exit(0);
					}
					else {
						level++;
						playing(playerlist);
					}
				}
				else {
					system("color 90");
					levelList[level].Stop();
					for (int i = 0; i < levelList[level].size(); i++)
						if (th[i].joinable()) th[i].join();
					int choice = a.drawNotification(40, 20, "YOU'VE PASS ALL LEVEL!","Wanna try again?", RED, 15, true);
					if (choice == 0) {
						a.drawNotification(40, 20, "BYE!! See ya!!", "Press any key to exit!", RED, YELLOW, true);
						_getch();
						File file;
						file.saveFile(playerlist);
						exit(0);
					}
					else {
						level = 0;
						playing(playerlist);
					}
				}
			}
		}
		else if (z == 'd') {
			mtx.lock();
			player->moveRight();
			mtx.unlock();
		}
		if (isImpact) {
			system("color 70");
			levelList[level].Stop();
			crash._play();
			player->drawEffect((player->getLane()) * 9 + 7);
			for (int i = 0; i < levelList[level].size(); i++)
				if (th[i].joinable()) th[i].join();
			int choice = a.drawNotification(40, 20, " YOU LOSE!", " Wanna try again!??", 242, 249, true);
			if (choice == 0) {
				File file;
				file.saveFile(playerlist);
				exit(0);
			}
			else {
				playing(playerlist);
			}
		}
	}

}
void Game::drawLevel() {
	mtx.lock();
	int temp = level + 1;
	Draw a;
	a.cursorPosition(106, 1);
	a.setTextColor(YELLOW); cout << "LEVEL";
	a.drawNumber(106 + 8, 2, temp % 10, BLUE);
	a.drawNumber(106, 2, temp/10 % 10, BLUE);
	player->drawInfo(106, 10);
	mtx.unlock();
}
