#include "HeaderFile/menu.h"
#include <conio.h>
void Menu::draw(int num) {
	Draw draw;
	for (int i = 0; i < item.size(); i++)
		draw.drawButton(item[i], (i == num) ? choose : normal, column, row + i);
}
int Menu::runMenu(int choice) {
	int z;
	choice = 0;
	draw(choice);
	while (true) {
		z = _getch();
		switch (z) {
		case 'w': {
			choice = (--choice < 0) ? 0 : choice;
			draw(choice);
			break;
		}
		case 's': {
			choice = ++choice%item.size();
			draw(choice);
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