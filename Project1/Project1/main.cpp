#include <iostream>
#include <conio.h>
#include <thread>
#include "HeaderFile/game.h"
#include "HeaderFile/menu.h"
#include "HeaderFile/file.h"
	
Draw a;	

using namespace std;

int startScreen(vector<Player> player);
int main() {
	vector<TrafficLight*> list_Light;
	vector<Level> level;
	File file;
	file.readData(level,list_Light);
	Player * player = NULL;
	vector<Player> playerlist;
	file.readFile(playerlist);
	a.setTextColor(YELLOW);
	cout << "\n\n                        THE CROSS ROAD GAME IS LOADING...";
	Sound sound("loop2.wav","loop");
	sound.open();
	sound.play();
	bool onSound = true;
	system("color 07");
	a.FixConsoleWindow();
	a.ShowConsoleCursor(invisible);
	int check = -1;
	vector<string> lSetting;
	lSetting.push_back("|Back");
	lSetting.push_back("|Mode:NORMAL");
	lSetting.push_back("|Sound:ON");
	//sound.stop();
	int mode = 1;
	Menu setting(lSetting,49,7,WHITE,BLUE);
	while (check) {
		check = startScreen(playerlist);
		if (check == 0) {
			Sound click("click.wav", "l");
			system("cls");
			a.drawFrame(49, 7,BLUE);
			a.cursorPosition(52, 9);
			a.setTextColor(YELLOW);
			cout << "Create new player";
			a.cursorPosition(52, 11);
			a.setTextColor(BLUE);
			cout << "Type yourname: ";
			a.cursorPosition(60, 14);
			a.setTextColor(GREEN);	
			cout << "[y]";
			a.setTextColor(15);
			cout << "es";
			a.cursorPosition(68, 14);
			a.setTextColor(RED);
			cout << "[n]";
			a.setTextColor(15);
			cout << "o";
			a.cursorPosition(52, 12);		
			a.setTextColor(15);
			cout << "________________";
			a.cursorPosition(52, 12);
			string name;
			getline(cin, name);
			while (true) {
				int z = _getch();
				click.play();
				if (z == 'y') {
					playerlist.push_back(Player(name, 20, 0));
					player = &playerlist.back();
					file.saveFile(playerlist);
					break;
				} 
				else if (z == 'n')
					break;
			}
		}
		else if (check == 1) {
			vector<string> m;
			for (int i = 0; i < playerlist.size(); i++) {
				m.push_back(playerlist[i].getName());
			}
			m.push_back("Back");
			Menu t(m, 49, 7);
			int x = t.runMenu();
			if (x != playerlist.size()) {
				player = &playerlist[x];
				break;
			}
		}
		else if (check == 2) {
			a.cursorPosition(49,5);
			a.setTextColor(YELLOW);
			cout << "<SETTING>";
			switch (setting.runMenu()) {
			case 1: {
				mode = ++mode % 3;
				if (mode == 0)
					setting.changeItem(1, "|Mode:EASY");
				else if (mode == 1)
					setting.changeItem(1, "|Mode:NORMAL");
				else
					setting.changeItem(1, "|Mode:HARD");
				break;
			}
			case 2:{
				onSound = !onSound;
				if (onSound) {
					setting.changeItem(2, "|SOUND:ON");
					sound.open();
					sound.play();
				}
				else {
					setting.changeItem(2, "|SOUND:OFF");
					sound.stop();
				}
				break;
			}
			}
			
		}
		if (check == 3) exit(0);
	}
	int lvlplay = 0;
	player = new Player("f",4,4);
	if (player && player->getHigestLevel() > 0) {
		vector<string> m;
		for (int i = 0; i < player->getHigestLevel(); i++) {
			m.push_back("Level" + to_string(i));
		}
		a.cursorPosition(45, 5);
		a.setTextColor(YELLOW);
		cout << "<RE-TRY LEVEL YOU'VE PASS>";
		Menu trylevel(m, 54, 7);
		lvlplay = trylevel.runMenu();
	}
	Game game(player, level, lvlplay, mode);
	game.playing(playerlist);
	system("pause");
	return 0;
}
int startScreen(vector<Player> player) {
	a.cursorPosition(20, 0);
	//a.changeFontSize(30);
	a.setTextColor(GREEN);
	cout << "========================================================================";
	a.cursorPosition(20, 1);
	cout << '"';
	a.setTextColor(PURPLE);
	cout << "  CCCC    A    RRRR    DDDD   OOOO  DDDD   GGGG   IIII NN   N  GGGG   ";
	a.setTextColor(GREEN);
	cout << '"';
	a.cursorPosition(20, 2);
	cout << '"';
	a.setTextColor(15);
	cout << " C       A A   R   R   D   D O    O D   D G        II  N N  N G       ";
	a.setTextColor(GREEN);
	cout << '"';
	a.cursorPosition(20, 3);
	cout << '"';
	a.setTextColor(BLUE);
	cout << " C      AAAAA  RRRR    D   D O    O D   D G   GGG  II  N   NN G   GGG ";
	a.setTextColor(GREEN);
	cout << '"';
	a.cursorPosition(20, 4);
	cout << '"';
	a.setTextColor(YELLOW);
	cout << "  CCCC A     A R   R   DDDD   OOOO  DDDD   GGGG   IIII N    N  GGGG   ";
	a.setTextColor(GREEN);
	cout << '"';
	a.cursorPosition(20, 5);
	cout << "========================================================================";
	a.drawDino(37, 9);
	a.drawHuman(64, 12);
	a.drawCar(41, 12, RIGHT);
	a.drawTruck(54, 12, RIGHT);
	a.drawBird(66, 7, LEFT);
	a.drawBird(68, 8, LEFT);
	a.setTextColor(GREEN);
	a.cursorPosition(20, 13);
	a.cursorPosition(20, 14);
	a.setTextColor(BLUE);
	cout << "#########################################################################";
	a.cursorPosition(20, 15);
	a.setTextColor(YELLOW);
	cout << "|Nguyen Truong Vinh Thuyen";
	a.cursorPosition(20, 16);
	cout << "|Nguyen Thi Kim Phuong";
	a.cursorPosition(20, 17);
	cout << "|Nguyen Hoang Tan";
	a.cursorPosition(20, 18);
	cout << "|Tran Trieu Thanh";
	vector<string> item;
	item.push_back("|New game|");
	item.push_back("|Load game|");
	item.push_back("|Setting|");
	item.push_back("|Exit|");
	Menu menu(item, 49, 7, WHITE, BLUE);
	if (player.size() == 0) return menu.runMenu(0, 1);
	return menu.runMenu(0, -1);
}
