#include "Field.h"
#include "ConsoleColor.h"

void Field::drawBorder() {
	for (int x = FIELD_MIN_X - 1; x <= FIELD_MAX_X; x++) {
		gotoxy(x, FIELD_MIN_Y - 1);
		std::cout << green <<  '_';
		gotoxy(x, FIELD_MAX_Y + 1);
		std::cout << green << '_';

	}
	for (int y = FIELD_MIN_Y; y <= FIELD_MAX_Y + 1; y++) {
		gotoxy(FIELD_MIN_X - 1, y);
		std::cout << green << '|';
		gotoxy(FIELD_MAX_X + 1, y);
		std::cout << green << '|';
	}
}
