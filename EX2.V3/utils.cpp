#include "utils.h"

BOOL gotoxy(const WORD x, const WORD y) {
	COORD xy;
	xy.X = x;
	xy.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

//void ShowConsoleCursor(bool showFlag)
//{
//	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	CONSOLE_CURSOR_INFO     cursorInfo;
//
//	GetConsoleCursorInfo(out, &cursorInfo);
//	cursorInfo.bVisible = showFlag; // set the cursor visibility
//	SetConsoleCursorInfo(out, &cursorInfo);
//}