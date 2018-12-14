//Vinh Thuyen
//11:17 PM 15/11/2018
//last change 6/12/2018
#ifndef _UI_H_ 
#define _UI_H_
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <Synchapi.h>
#include <conio.h>
#include <mmsystem.h>
#include <cwchar>

#define LIGHTBLUE 27
#define WHITE 8
#define YELLOW 174
#define RED 108
#define GREEN 186
#define GREY 119
#define PURPLE 77
#define BLUE 9
#define BLACK 0
#define visible true
#define invisible false
#define RIGHT true
#define LEFT false
#define MAXLENGHT 100

typedef bool Direction;
typedef int Color;

using namespace std;

class View {
private:
public:
	void FixConsoleWindow();
	void cursorPosition(int column, int row);
	void ShowConsoleCursor(bool showFlag);
	void setTextColor(Color color);
	void changeFontSize(int size);
	void setWindowSize(int w, int h) {}

};
class Draw : public View {
private:
public:
	void drawHuman(int column, int row);
	void drawBird(int column, int row, Direction direct);
	void drawCar(int column, int row, Direction direct);
	void drawTruck(int column, int row, Direction direct);
	void drawDino(int column, int row);
	void drawButton(string text, Color color, int column, int row);
	void drawFrame(int column, int row, Color color = BLACK);
	int drawNotification(int column, int row, string text, string text2 = " ", Color frame = RED, Color ctext = WHITE, bool canChoose = false);
	void drawTrafficLight(int column, int row, bool isRed);
	void drawNumber(int column, int row, int number, Color color = WHITE);
	void drawEffect(int column, int row, Color color = RED);
	void deleteHuman(int column, int row);
};
	
#endif
