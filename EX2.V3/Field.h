#pragma once
#include "utils.h"
#include <iostream>
#include "ConsoleColor.h"

enum { FIELD_MIN_X = 1, FIELD_MAX_X = 80, FIELD_MAX_Y = 25, FIELD_MIN_Y = 4 };
class Field {
private:
	char m_Field[FIELD_MAX_Y][FIELD_MAX_X] = {};

public:
	char getField(int x, int y) {
		return m_Field[y][x];
	}

	bool isCoordEmpty(int x, int y) {
		char c = getField(x, y);
		return (c == 0 || c == ' ');
	}

	void setCharInField(int x, int y, char c) {
		m_Field[y][x] = c;
		gotoxy(x, y);
		std::cout << red << c;
	}

	void drawBorder();

};

//todo singleton
extern Field field;