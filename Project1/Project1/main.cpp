#include <iostream>
#include <conio.h>
#include <thread>
#include "HeaderFile/game.h"
#include "HeaderFile/menu.h"

	

using namespace std;
Draw a;
int startScreen() {
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
	a.drawCar(41, 12,RIGHT);
	a.drawTruck(54, 12, RIGHT);
	a.drawBird(66, 7,LEFT);
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
	Menu menu(item,49,7,WHITE,BLUE);
	return menu.runMenu();
}
int main() {
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
		check = startScreen();
		if (check == 0) {

		}
		else if (check == 1) {

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
	//system("pause");
	TrafficLight trafficlight;
	TrafficLight trafficlight2(true,9000,4000);
	Player player("Teasdasdst", 10,1);
	vector<mObject*> obj;
	obj.push_back(new Bird(RIGHT, 3));
	obj.push_back(new Dino(RIGHT, 15));
	obj.push_back(new Truck(RIGHT, 79));
	vector<mObject*> obj1;
	obj1.push_back(new Truck(LEFT, 30));
	obj1.push_back(new Car(LEFT, 50));
	obj1.push_back(new Bird(LEFT, 4));
	vector<mObject*> obj3;
	obj3.push_back(new Bird(RIGHT, 3));
	obj3.push_back(new Dino(RIGHT, 15));
	obj3.push_back(new Truck(RIGHT, 79));
	vector<mObject*> obj4;
	obj4.push_back(new Truck(LEFT, 30));
	obj4.push_back(new Car(LEFT, 50));
	obj4.push_back(new Bird(LEFT, 4));
	vector<mObject*> obj5;
	obj4.push_back(new Truck(LEFT, 30));
	obj4.push_back(new Car(LEFT, 50));
	obj4.push_back(new Bird(LEFT, 4));
	vector<mObject*> obj2;
	Lane lane0(obj2, RIGHT, 100, NULL);
	Lane lane(obj, RIGHT, 100, NULL, &trafficlight2);
	Lane lane1(obj1, LEFT, 200, NULL, NULL);
	Lane lane2(obj2, RIGHT, 100, &player);
	Lane lane3(obj3, RIGHT, 100, NULL);
	Lane lane4(obj4, LEFT, 100, NULL);
	Lane lane5(obj5, LEFT, 100, NULL);
	vector<Lane*> l;
	l.push_back(&lane);
	l.push_back(&lane3);
	l.push_back(&lane5);

	l.push_back(&lane4);
	l.push_back(&lane2);
	vector<Lane*> l2;
	l2.push_back(&lane3);
	l2.push_back(&lane4);
	l2.push_back(&lane2);
	vector<Level> level;
	level.push_back(l);	
	level.push_back(l);
	level.push_back(l2);
	level.push_back(l2);
	level.push_back(l);
	level.push_back(l);
	level.push_back(l2);
	level.push_back(l2);
	level.push_back(l);
	level.push_back(l);
	level.push_back(l2);
	level.push_back(l2);
	Game game(&player, level, 0);
	game.playing();
	system("pause");
	return 0;
}
