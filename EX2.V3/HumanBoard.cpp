#include "HumanBoard.h"



void HumanBoard::handleKey(char c)
{
	if (c == kbChars[kbup] && getTop().getY() > FIELD_MIN_Y) {
		getBottom().erase();
		getBottom().setDirection(0, -1);
		getTop().setDirection(0, -1);
		getBottom().move();
		getTop().move();
		getTop().draw();
	}
	else if (c == kbChars[kbdown] && getBottom().getY() < FIELD_MAX_Y) {
		getTop().erase();
		getBottom().setDirection(0, 1);
		getTop().setDirection(0, 1);
		getBottom().move();
		getTop().move();
		getBottom().draw();
	}
}


