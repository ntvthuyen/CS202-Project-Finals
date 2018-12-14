#include "HeaderFile/menu.h"
#include <conio.h>
void Menu::draw(int num, int hidden) {
	Draw draw;
	if(hidden == -1)
	for (int i = 0; i < item.size(); i++)
		draw.drawButton(item[i], (i == num) ? choose : normal, column, row + i);
	else {
		int temp = 0;
		for (int i = 0; i < item.size(); i++) {
			if (i != hidden) {
				draw.drawButton(item[i], (i == num) ? choose : normal, column, row + temp);
				temp++;
			}
		}
	}
}
int Menu::runMenu(int choice, int hiddenItem) {
	int z;
	Sound sound("click.wav", "click");
	//sound.open();
	choice = 0;
	draw(choice, hiddenItem);
	while (true) {
		z = _getch();
		sound._play();
		switch (z) {
		case 'w': {
			choice = (--choice < 0) ? 0 : choice;
			if (hiddenItem != -1) {
				if (choice == hiddenItem) choice = (--choice < 0) ? 0 : choice;
				if (hiddenItem == 0 && choice == 0) choice = 1;
			}
			draw(choice, hiddenItem);
			break;
		}
		case 's': {
			choice = ++choice%item.size();
			if (choice == hiddenItem) ++choice%item.size();
			draw(choice, hiddenItem);
			break;
		}
		case 13: {
			system("cls");
			return choice;
		}
		}
	}
}
void Menu::changeItem(vector<string> item) {
	this->item = item;
}
void Menu::changeItem(int i, string item) {
	if (i < this->item.size()) {
		this->item[i] = item;
	}
}