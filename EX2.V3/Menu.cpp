#include "Menu.h"

void Menu::open() {

	int x = 20,
		y = 10,
		z = 3;

	switch (currentScreen){
	case Menu::MAIN_MENU:
		field.drawBorder();
		for (auto& c : main_menu) {
			if (c == '\n') {
				x = 20;
				y++;
			}
			field.setCharInField(x, y, c);
			x++;
			Sleep(20);
		}
		/*field.setCharInField(x, y, ' ');
		std::cout << main_menu;*/
		break;

	case Menu::PAUSE_MENU:
		field.drawBorder();
		for (auto& c : pause_menu) {
			if (c == '\n') {
				x = 20;
				y++;
			}
			field.setCharInField(x, y, c);
			x++;
			Sleep(20);
		}
		/*field.setCharInField(x, y, ' ');
		std::cout << pause_menu;*/
		break;

	case Menu::INSTRUCTIONS:
		field.drawBorder();
		for (auto& c : instructions) {
			if (c == '\n') {
				z = 3;
				y++;
			}
			field.setCharInField(z, y, c);
			z++;
			Sleep(20);
		}
		break;

	case Menu::HVSC_MODE_MENU:
		field.drawBorder();
		for (auto& c : difficulty_HVSC) {
			if (c == '\n') {
				z = 3;
				y++;
			}
			field.setCharInField(z, y, c);
			z++;
			Sleep(20);
		}
		//game.waitForKey();
		break;

	case Menu::CVSC_LEFT_MODE_MENU :
		field.drawBorder();
		for (auto& c : left_board_mode) {
			if (c == '\n') {
				z = 3;
				y++;
			}
			field.setCharInField(z, y, c);
			z++;
			Sleep(20);
		}
		break;
	case Menu::CVSC_RIGHT_MODE_MENU:
		field.drawBorder();
		for (auto& c : right_board_mode) {
			if (c == '\n') {
				z = 3;
				y++;
			}
			field.setCharInField(z, y, c);
			z++;
			Sleep(20);
		}
		break;

		/*field.setCharInField(z, y, ' ');
		std::cout << instructions;*/
		break;

	default:
		break;
	}

}

void Menu::handleKey(char c) {
	//new game - human vs human
	if ((currentScreen == Screen::MAIN_MENU || currentScreen == Screen::PAUSE_MENU) && c == kbChars[newGame_HVSH] && (game.getStatus() == PAUSE || game.getStatus() == FIRST_GAME)) {
		game.setMode(HVSH);
		game.changeStatus(RESTART);
		return;
	}

	//new game - human vs computer
	if ((currentScreen == Screen::MAIN_MENU || currentScreen == Screen::PAUSE_MENU) && c == kbChars[newGame_HVSC] && (game.getStatus() == PAUSE || game.getStatus() == FIRST_GAME)) {
		game.setMode(HVSC);
		currentScreen = Screen::HVSC_MODE_MENU;
		system("cls");
		open();
		return;
	}

	//new game - computer vs computer
	if ((currentScreen == Screen::MAIN_MENU || currentScreen == Screen::PAUSE_MENU) && c == kbChars[newGame_CVSC] && (game.getStatus() == PAUSE || game.getStatus() == FIRST_GAME)) {
		game.setMode(CVSC);
		//game.changeStatus(RESTART);
		currentScreen = Screen::CVSC_LEFT_MODE_MENU;
		system("cls");
		open();
		return;
	}

	//continue current game
	if (currentScreen == Screen::PAUSE_MENU && c == kbChars[Continue] && game.getStatus() == PAUSE ) {
		game.changeStatus(PLAY);
		return;
	}

	//open instructions menu
	if (c == kbChars[Instructions] && (currentScreen == Screen::MAIN_MENU || currentScreen == Screen::PAUSE_MENU) && (game.getStatus() == PAUSE || game.getStatus() == FIRST_GAME)) {
		currentScreen = Screen::INSTRUCTIONS;
		system("cls");
		open();
		return;
	}

	//close instructions menu
	if (c == kbChars[Back] && currentScreen == Screen::INSTRUCTIONS) {
		currentScreen = Screen::MAIN_MENU;
		system("cls");
		open();
		return;
	}

	//exit game from main menu or pause menu
	if ((currentScreen == Screen::MAIN_MENU || currentScreen == Screen::PAUSE_MENU) && c == kbChars[Exit] && (game.getStatus() == PAUSE || game.getStatus() == FIRST_GAME)) {
		game.changeStatus(QUIT);
		return;
	}

	//open pause menu from gameplay
	if ((currentScreen == Screen::MAIN_MENU || currentScreen == Screen::PAUSE_MENU) && c == kbChars[Open] && game.getStatus() == PLAY) {
		game.changeStatus(PAUSE);
		return;
	}

	// HVSC set difficulty
	if ((c == kbChars[NOVICE] || c == kbChars[GOOD] || c == kbChars[BEST]) && currentScreen == Screen::HVSC_MODE_MENU && (game.getStatus() == PAUSE || game.getStatus() == FIRST_GAME)) {
		currentScreen = Screen::PAUSE_MENU;
		game.setRightDifficulty(c);
		game.changeStatus(RESTART);
		system("cls");
		return;
	}

	// CVSC set left mode
	if ((c == kbChars[NOVICE] || c == kbChars[GOOD] || c == kbChars[BEST]) && currentScreen == Screen::CVSC_LEFT_MODE_MENU && (game.getStatus() == PAUSE || game.getStatus() == FIRST_GAME)) {
		currentScreen = Screen::PAUSE_MENU;
		game.setLeftDifficulty(c);
		game.setRightDifficulty(c);
		currentScreen = Screen::CVSC_RIGHT_MODE_MENU;
		system("cls");
		open();
		return;
	}

	// CVSC set right mode
	if ((c == kbChars[NOVICE] || c == kbChars[GOOD] || c == kbChars[BEST]) && currentScreen == Screen::CVSC_RIGHT_MODE_MENU && (game.getStatus() == PAUSE || game.getStatus() == FIRST_GAME)) {
		currentScreen = Screen::PAUSE_MENU;
		game.setLeftDifficulty(c);
		game.setRightDifficulty(c);
		game.changeStatus(RESTART);
		system("cls");
		return;
	}
}