#pragma once
#include <typeinfo>
#include "Field.h"
#include "utils.h"
#include "Menu.h"
#include "KeyboardManager.h"
#include "Ball.h"
#include "Board.h"
#include "DeadZone.h"
#include "PCboard.h"
#include "HumanBoard.h"


class KeyboardManager;
class Menu;

using namespace std;

enum status { PAUSE, RESTART, QUIT, PLAY, FIRST_GAME };
enum difficulty { NOVICE, GOOD, BEST };
enum mode { HVSH, HVSC, CVSC };

class Game {
public:
	enum zones{ LEFT = 1, RIGHT = -1, MAX_X = 20, MAX_Y = 25, LEFTLOOSE = 20, RIGHTLOOSE = 60 };
	const char* kbChars = "\x1b";

private:
	status currentStat = FIRST_GAME;
	difficulty currentDif = GOOD;
	mode currentMode = HVSC;
	int leftPCDif = BEST,
	rightPCDif = BEST;

public:
	void run();

	void changeStatus(status newStatus) {
		currentStat = newStatus;
	}

	status getStatus() {
		return currentStat;
	}

	void setMode(mode newMode) {
		currentMode = newMode;
	}

	const char* getKbChars() {
		return kbChars;
	}

	void handleKey(char c) {
		currentStat = PAUSE;
	}

	void waitForKey(KeyboardManager *kbManager);

	void getTenKeys(KeyboardManager *kbManager);

	void checkForHit(Board &board, DeadZone &zone, Ball &ball, bool &movePC);

	void setLeftDifficulty(char c) {
		if (c - '1' == NOVICE)
			leftPCDif = NOVICE;
		if (c - '2' == GOOD)
			leftPCDif = GOOD;
		if (c - '3' == BEST)
			leftPCDif = BEST;
	}

	void setRightDifficulty(char c) {
		if (c - '1' == NOVICE)
			rightPCDif = NOVICE;
		if (c - '2' == GOOD)
			rightPCDif = GOOD;
		if (c - '3' == BEST)
			rightPCDif = BEST;
	}
};

// extern for global var
// TODO: this is not nice
// we don't like gloval variables
// better: make it Singleton (or other solution)
extern Game game;