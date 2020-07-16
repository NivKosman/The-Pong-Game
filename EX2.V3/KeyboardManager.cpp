#include <conio.h>
#include "KeyboardManager.h"

void KeyboardManager::registerKbListener(HumanBoard * pKbListener) {

	const char * chars = pKbListener->getKbChars();
	size_t numCharToRegister = strlen(chars);
	for (size_t i = 0; i < numCharToRegister; ++i) {
		int index = getIndex(chars[i]);
		if (index != -1) {
			board_kbListeners[index].push_back(pKbListener);
		}
	}
}

void KeyboardManager::unRegisterKbListener(HumanBoard* pKbListener) {

	const char * chars = pKbListener->getKbChars();
	size_t numCharToRegister = strlen(chars);
	for (size_t i = 0; i < numCharToRegister; ++i) {
		int index = getIndex(chars[i]);
		if (index != -1) {
			board_kbListeners[index].remove(pKbListener);
		}
	}
}

void KeyboardManager::registerKbListener(Menu * pKbListener) {

	const char * chars = pKbListener->getKbChars();
	size_t numCharToRegister = strlen(chars);
	for (size_t i = 0; i < numCharToRegister; ++i) {
		int index = getIndex(chars[i]);
		if (index != -1) {
			menu_kbListener[index].push_back(pKbListener);
		}
	}
}

void KeyboardManager::registerKbListener(Game * pKbListener) {

	const char * chars = pKbListener->getKbChars();
	size_t numCharToRegister = strlen(chars);
	for (size_t i = 0; i < numCharToRegister; ++i) {
		int index = getIndex(chars[i]);
		if (index != -1) {
			game_kblistener= pKbListener;
		}
	}
}

void KeyboardManager::handleKeyboard()
{
	if (_kbhit()) {
		char k = tolower(_getch());
		int index = getIndex(k);
		if(k == '\x1b')
			if(game.getStatus() != PAUSE)
				game.changeStatus(PAUSE);
			else
				for (auto pKbListener : menu_kbListener[index]) {
					pKbListener->handleKey(k);
				}
		else {
			if (index != -1) {
				if (game.getStatus() == PLAY)
					for (auto pKbListener : board_kbListeners[index]) {
						pKbListener->handleKey(k);
					}
				if (game.getStatus() == PAUSE || game.getStatus() == FIRST_GAME) {
					for (auto pKbListener : menu_kbListener[index]) {
						pKbListener->handleKey(k);
					}
				}
			}
		}
	}
}
