#pragma once
#include <list>
#include "Game.h"

class HumanBoard;
class Menu;
class Game;

using namespace std;

class KeyboardManager {
private:
	// TODO: in the future we will hold KeyboardEventListener
	// but since we didn't learn inheritance yet, we just hold the actual type for now
	enum { NUM_CHARS = 26 };
	// an array of 'char' => list of kbListener
	list<HumanBoard*> board_kbListeners[NUM_CHARS];
	list<Menu*> menu_kbListener[10];
	Game* game_kblistener;

	// helper method - get index in array per a given char
	int getIndex(char c) {
		int index = c - 'a';
		if (index >= 0 && index <= NUM_CHARS)
			return index;

		index = c - 'A';
		if (index >= 0 && index <= NUM_CHARS)
			return index;

		index = c - '0';
		if(index >= 0 && index <= 9)
			return index;

		if (c == '\x1b')
			return -3;

		return -1;


	/*	int index = c - 'a';
		if (index < 0 || index >= NUM_CHARS) {
			index = c - 'A';
			if (index < 0 || index >= NUM_CHARS) {
				return -1;
			}
		}
		return index;*/
	}

public:
	void registerKbListener(HumanBoard* pKbListener);
	
	void registerKbListener(Menu * pKbListener);
	
	void registerKbListener(Game * pKbListener);

	void unRegisterKbListener(HumanBoard* pKbListener);
	
	void handleKeyboard();
};