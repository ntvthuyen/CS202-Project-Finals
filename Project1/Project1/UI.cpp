 #include "HeaderFile/UI.h"

void View::FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void View::cursorPosition(int column, int row) {
	COORD point;
	point.X = column; point.Y = row;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
void View::ShowConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
void View::setTextColor(Color color) {
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0; wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void View::changeFontSize(int size){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = size;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	//std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void Draw::drawHuman(int column, int row) {
	cursorPosition(column - 1, row - 1);
	cout << "   ";
	cursorPosition(column - 1, row);
	cout << "   ";
	cursorPosition(column - 1, row + 1);
	cout << "   ";
	cursorPosition(column, row - 1);
	setTextColor(WHITE);
	cout << char(220); // draw head
	setTextColor(LIGHTBLUE);
	cursorPosition(column-1, row);
	cout << '/' << char(219) << '\\';
	setTextColor(RED);
	cursorPosition(column , row + 1);	
	cout << char(186);
}
//   /\
// =(  o)>
// 
// =(__o)>
//
// =(  o)>
//	 \/



//    /\
// <(o  )=
// 
// <(o__)=
//
// <(o  )=
//    \/
void Draw::drawBird(int column, int row, Direction direct) {
	if (direct) {
		setTextColor(LIGHTBLUE);
		cursorPosition(column - 3, row);
		cout << "=(  o)";
		setTextColor(YELLOW);
		cout << '>';
		cursorPosition(column - 1, row + 1);
		cout << "``";
		setTextColor(LIGHTBLUE);
		int temp = column % 3;
		if (temp % 3 == 0) {
			cursorPosition(column - 1, row - 1);
			cout << "/\\";
		}
		else if (temp % 3 == 1) {
			cursorPosition(column - 1, row);
			cout << "__";
		}
		else {
			cursorPosition(column - 1, row + 1);
			cout << "\\/";
		}
	}
	else
	{
		cursorPosition(column - 3, row);
	
		setTextColor(YELLOW);
		cout << '<';
		setTextColor(LIGHTBLUE);
		cout << "(o  )=";
		setTextColor(YELLOW);
		cursorPosition(column, row + 1);
		cout << "``";
		setTextColor(LIGHTBLUE);
		int temp = column % 3;
		if (temp % 3 == 0) {
			cursorPosition(column, row - 1);
			cout << "/\\";
		}
		else if (temp % 3 == 1) {
			cursorPosition(column, row);
			cout << "__";
		}
		else {
			cursorPosition(column, row + 1);
			cout << "\\/";
		}
	}
}
//        ___
//       /o  \
//      |  vvv
//     /    /
//    |  \/ |\/
//   /    \
//  // \ |\ |
// /        L

//        ___
//       /o  \
//      |  vvv
//     /    /
//    |  \/|\/
//   /     \
//  // \ |\ |
// /     L  L

//        ___
//       /o  \
//      |  vvv
//     /    /
//    |  \/|\/
//   /     \
//  // \ |\ |
// /     L   
void Draw::drawDino(int column, int row) {
	setTextColor(GREEN);
	cursorPosition(column - 5, row-3);
	cout << "      ___";
	cursorPosition(column - 5, row - 2);
	cout << "     /";
	setTextColor(RED);
	cout << "o";
	setTextColor(GREEN);
	cout << "  \\";
	cursorPosition(column - 5, row - 1);
	cout << "    |";
	setTextColor(15);
	cout << "  vvv";
	setTextColor(GREEN);
	cursorPosition(column - 5, row );
	cout << "    /    /";
	cursorPosition(column - 5, row + 1);
	cout << "   |  \\/|\\/";
	cursorPosition(column - 5, row + 2);
	cout << "  /     \\";
	cursorPosition(column - 5, row  + 3);
	cout << " // \\ |\\ |";
	int temp = column % 4;
	switch (temp) {
	case 0: {
		cursorPosition(column - 5, row + 1);
		cout << "   |  \\/|\\/";
		cursorPosition(column - 5, row + 4);
		cout << "/     L  L";
		break;
	}
	case 1: {
		cursorPosition(column - 5, row + 1);
		cout << "   |  \\/|\\_";
		cursorPosition(column - 5, row + 4);
		cout << "/        L";
		break;

	}
	case 2: {
		cursorPosition(column - 5, row + 1);
		cout << "   |  \\/|\\/";
		cursorPosition(column - 5, row + 4);
		cout << "/     L  L";
		break;

	}
	case 3: {
		cursorPosition(column - 5, row + 1);
		cout << "   |  \\_|\\/";
		cursorPosition(column - 5, row + 4);
		cout << "/     L";
		break;
	}
	}
}
// ______ 
//|[_] [_\
//'O----O-*
//

//   ______ 
//  /_] [_]|
// *O----O-'
//
void Draw::drawCar(int column, int row, Direction direct){
	if (direct) {
		setTextColor(GREEN);
		cursorPosition(column - 4, row - 1);
		cout << " ______";
		cursorPosition(column - 4, row);
		cout << "|"; setTextColor(LIGHTBLUE);
		cout << "[_] [_\\";
		setTextColor(GREEN);
		cursorPosition(column - 4, row + 1);
		cout << "'O----O-";
		setTextColor(YELLOW);
		cout << "*";
	}
	else {
		setTextColor(GREEN);
		cursorPosition(column - 4, row - 1);
		cout << "  ______";
		cursorPosition(column - 4, row);
		setTextColor(LIGHTBLUE);
		cout << " /_] [_]";
		setTextColor(GREEN);
		cout << "|";
		setTextColor(YELLOW);
		cursorPosition(column - 4, row + 1);
		cout << "*";
		setTextColor(GREEN);
		cout << "O----O-'";
	}
}
//
//         ___
//|XxXxX| | [_|
//'0---0=-'-0-*

//
// ___
//|_] | |XxXxX|
//*-0-'-=0---0' 
void Draw::drawTruck(int column, int row, Direction direct){
	if (direct) {
		setTextColor(RED);
		cursorPosition(column - 6, row - 1);
		cout << "         ___";
		setTextColor(WHITE);
		cursorPosition(column - 6, row);
		cout << "|XxXxX|"; setTextColor(RED);
		cout << " | [_|";
		setTextColor(GREEN);
		cursorPosition(column - 6, row + 1);
		setTextColor(RED);
		cout << "'0---0=-'-0-";
		setTextColor(YELLOW);
		cout << "*";
	}
	else {
		setTextColor(RED);
		cursorPosition(column - 6, row - 1);
		cout << " ___";
		setTextColor(RED);
		cursorPosition(column - 6, row);
		cout << "|_] |";
		 setTextColor(WHITE);
		cout << " |XxXxX|";
		setTextColor(GREEN);
		cursorPosition(column - 6, row + 1);
		setTextColor(YELLOW);
		cout << "*";
		setTextColor(RED);
		cout << "-0-'-=0---0'";
	}

}
void Draw::drawButton(string text, Color color, int column, int row) {
	cursorPosition(column, row);
	setTextColor(color);
	cout << text;
}
void Draw::drawFrame(int column, int row, Color color) {
	setTextColor(color);
	cursorPosition(column, row);
	cout << "_______________________________";
	cursorPosition(column, row + 1);
	cout << "||                           ||";
	cursorPosition(column, row + 2);
	cout << "||                           ||";
	cursorPosition(column, row + 3);
	cout << "||                           ||";
	cursorPosition(column, row + 4);
	cout << "||                           ||";
	cursorPosition(column, row + 5);
	cout << "||___________________________||";
}
int Draw::drawNotification(int column, int row, string text, Color frame, Color ctext, bool canChoose) {
	setTextColor(frame);
	cursorPosition(column, row);
	cout << " ___________________________";
	cursorPosition(column, row + 1);
	cout << "|                           |";
	cursorPosition(column, row + 2);
	cout << "|                           |";
	cursorPosition(column, row + 3);
	cout << "|                           |";
	cursorPosition(column, row + 4);
	cout << "|                           |";
	cursorPosition(column, row + 5);
	cout << "|___________________________|";
	cursorPosition(column+1, row + 2 );
	setTextColor(ctext);
	cout << text;
	if (canChoose) {
	cursorPosition(column + 5, row + 4);
	setTextColor(GREEN);
	cout << "[Y]";
	setTextColor(ctext);
	cout << "es    ";
	setTextColor(RED);
	cout << "[N]";
	setTextColor(ctext);
	cout << "o";
	int z;
	while (true) {
		z = _getch();
		if (z == 'y') {
			return 1;
		}
		else if (z == 'n') {
			return 0;
		}
	}
	}
	return 0;
}
void Draw::drawTrafficLight(int column, int row, bool isRed) {
	cursorPosition(column, row);
	if (isRed) {
		setTextColor(WHITE);
		cout << char(219) << char(129);
		setTextColor(RED);
		cout << char(219) << char(129);
	}
	else {
		setTextColor(GREEN);
		cout << char(219) << char(129);
		setTextColor(WHITE);
		cout << char(219) << char(129);
	}
}