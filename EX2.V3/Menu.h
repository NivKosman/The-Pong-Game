#pragma once
#include <string>
#include "utils.h"
#include "Field.h"
#include "Game.h"
#include "PCboard.h"

using namespace std;
class Menu {
public:
	enum Screen { MAIN_MENU, PAUSE_MENU, INSTRUCTIONS, HVSC_MODE_MENU, CVSC_LEFT_MODE_MENU, CVSC_RIGHT_MODE_MENU};

private:
	//PCboard *pPCLeft = nullptr;
	//PCboard *pPCRight = nullptr;
	const char* kbChars = "1234890";
	const string main_menu = "main menu:\n (1) Start a new game - Human vs Human\n (2) Start a new game - Human vs Computer\n (3) Start a new game - Computer vs Computer\n (8) Present instructions and keys\n (9) EXIT";
	const string pause_menu = "main menu:\n (1) Start a new game - Human vs Human\n (2) Start a new game - Human vs Computer\n (3) Start a new game - Computer vs Computer\n (4) Continue\n (8) Present instructions and keys\n (9) EXIT";
	const string instructions = "If you're playing this I assume you know what to do, but in case you hit\n"
		"your head and forgot:\n"
		"The game is a double player pong where each player must not let the ball\n"
		"pass its board. Ones one of the players misses the ball his playing board\n"
		"descents into a tetris oblivion and his new board moves a step forward,\n"
		"making the next round a bit harder for the losing party.\n\n"
		"The controls are as follows:\n"
		"     | Left Player | Right Player |\n"
		"Up   | q or Q      | p or P       |\n"
		"Down | a or A      | l or L       |\n"
		"\n\n"
		"Press 0 to go back.";
	const string difficulty_HVSC = " choose difficulty:\n (1) NOVICE\n (2) GOOD\n (3) BEST";
	const string left_board_mode = " choose mode for left board:\n (1) NOVICE\n (2) GOOD\n (3) BEST";
	const string right_board_mode = " choose mode for right board:\n (1) NOVICE\n (2) GOOD\n (3) BEST";
	enum main_buttons { newGame_HVSH, newGame_HVSC, newGame_CVSC, Continue, Instructions, Exit, Back, Open };
	enum mode_buttons { NOVICE, GOOD, BEST };
	Screen currentScreen;
	//const char* kbChars = "\b";
	char foo;

public:
	const char* getKbChars() {
		return kbChars;
	}
	
	void changeScreen(Screen newScreen) {
		currentScreen = newScreen;
	}
	
	void handleKey(char c);
	
	void open();
	
	//void setPCBoardsPointers(PCboard *left, PCboard *right) {
	//	pPCLeft = left;
	//	pPCRight = right;
	//}

};

extern Menu menu;