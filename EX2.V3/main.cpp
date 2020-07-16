#include "Game.h"

//enum { LEFT = 1, RIGHT = -1, MAX_X = 20, MAX_Y = 25, LEFTLOOSE = 20, RIGHTLOOSE = 60 };

Game game;
Menu menu;
Field field;

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}


int main() {
	ShowConsoleCursor(false);

	game.run();
	
}