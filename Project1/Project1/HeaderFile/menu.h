#pragma once
#ifndef _menu_h_
#define _menu_h_
#include "UI.h"
#include "sound.h"
class Menu {
private:
	vector<string> item;
	int column, row;
	Color normal , choose;
public:
	Menu(vector<string> item, int column, int row, Color normal = WHITE, Color choose = LIGHTBLUE): item(item), column(column), row(row), normal(normal), choose(choose){}
	int runMenu(int choice = 0, int hiddenItem = -1);
	void draw(int num, int hidden);
	void changeItem(vector<string> Item);
	void changeItem(int i, string item);
};

#endif