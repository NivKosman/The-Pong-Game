#include "Game.h"
//#include "KeyboardManager.h"

using namespace std;

void Game::run()
 {
	KeyboardManager kbManager;
	kbManager.registerKbListener(&menu);

	do { 
		//-initializtions:
		//prepare ball
		Point point;
		Ball ball;
		point.setPoint(40, 18, 'O');
		ball.set(point);
		ball.Rand_dir();

		//set tetris zones
		DeadZone Zoneleft(LEFT);
		DeadZone Zoneright(RIGHT);
		const char* kbLeftChars = "qa";
		const char* kbRightChars = "pl";

		//prepare boards
		HumanBoard leftBoard({ 4, 10, '#' }, { 4, 12, '#' }, LEFT, kbLeftChars);
		HumanBoard rightBoard({ 76, 11, '#' }, { 76, 13, '#' }, RIGHT, kbRightChars);
		PCboard PC_leftBoard({ 4, 10, '#' }, { 4, 12, '#' }, LEFT, &leftPCDif, &ball);
		PCboard PC_rightBoard({ 76, 11, '#' }, { 76, 13, '#' }, RIGHT, &rightPCDif, &ball);

		bool missed = false,
			moveRightPC = true,
			moveLeftPC = true;
		int when_lose_left = PC_leftBoard.rand_lose();
		int when_lose_right = PC_rightBoard.rand_lose();
		//-end of initializations.
		
		//set players
		Board *leftPlayer = nullptr;
		Board *rightPlayer = nullptr;

		//screens switch
		switch (currentStat) { 
		case FIRST_GAME: //open main menu
			menu.open();
			waitForKey(&kbManager);
			system("cls");
			field.drawBorder();
			game.changeStatus(PLAY);
			break;

		case PLAY: //game loop
			switch (currentMode) {
			case HVSC:
				leftPlayer = &leftBoard;
				rightPlayer = &PC_rightBoard;

				kbManager.registerKbListener(&leftBoard);
				break;

			case HVSH:
				leftPlayer = &leftBoard;
				rightPlayer = &rightBoard;

				kbManager.registerKbListener(&leftBoard);
				kbManager.registerKbListener(&rightBoard);
				break;

			case CVSC:
				leftPlayer = &PC_leftBoard;
				rightPlayer = &PC_rightBoard;
				break;
			}

			if (leftPlayer != nullptr && rightPlayer != nullptr) {
				leftPlayer->draw();
				rightPlayer->draw();

				while (leftPlayer->getX() <= LEFTLOOSE &&
					rightPlayer->getX() >= RIGHTLOOSE &&
					game.getStatus() != RESTART &&
					game.getStatus() != QUIT) {
					// check if pc player needs to move
					if (moveRightPC && typeid(*rightPlayer) == typeid(PCboard)){
						if(when_lose_right>PC_rightBoard.Get_counter()||when_lose_right==-1)
						{
							waitForKey(&(kbManager));
						rightPlayer->handleKey('l');// ignoring char
						}
						else {
							waitForKey(&(kbManager));
							PC_rightBoard.move_to_lose();
						}
					}

					if (moveLeftPC && typeid(*leftPlayer) == typeid(PCboard)){
						if (when_lose_left > PC_leftBoard.Get_counter()||when_lose_left==-1)
							leftPlayer->handleKey('l');// ignoring char
						else {
							PC_leftBoard.move_to_lose();
						} 
					}

					// check for active menu
					if (game.getStatus() == PAUSE) {
						menu.changeScreen(Menu::PAUSE_MENU);
						menu.open();
						waitForKey(&kbManager);
						system("cls");
						leftPlayer->draw();
						rightPlayer->draw();
						field.drawBorder();
					}

					getTenKeys(&kbManager);
					ball.moveBall();

					checkForHit(*leftPlayer, Zoneleft, ball, moveRightPC);
					checkForHit(*rightPlayer, Zoneright, ball, moveLeftPC);
				} // TODO game over function
				system("cls");
			}
			break;

		case RESTART:
			kbManager.unRegisterKbListener(&leftBoard);
			kbManager.unRegisterKbListener(&rightBoard);
			game.changeStatus(PLAY);
			field.drawBorder();
			break;
		}

	} while (game.getStatus() != QUIT);
}

void Game::waitForKey(KeyboardManager *kbManager) {
	while (game.getStatus() == PAUSE || game.getStatus() == FIRST_GAME) {
		kbManager->handleKeyboard();
		Sleep(10);
	}
}

void Game::getTenKeys(KeyboardManager *kbManager) {
	for (int i = 0; i < 10; ++i) {
		kbManager->handleKeyboard();
		Sleep(10);
	}
}

void Game::checkForHit(Board &board, DeadZone &zone, Ball &ball, bool &movePC) {
	int temp;
	BOOL clear;

	Board::BallPosition boardState = board.checkBallPosition(ball);
	switch (boardState) {
	case Board::BallPosition::AWAY:
		break;

	case Board::BallPosition::MISSED:
		temp = zone.draw_drop(board.getX(), board.getUpperY());
		clear = zone.check_clear(temp);
		if (clear)
		{
			zone.change_full_line(temp);
			zone.drop_cause_full_line(temp);
			board.erase_board();
			board.board_plus5();
			board.draw();
		}
		else
		{
			board.ChangeBoard_Cause_Lose();
			board.draw();
		}
		ball.eraseball();
		ball.reset();
		ball.Rand_dir();
		break;

	case Board::BallPosition::CORNER_HIT:
		ball.changeYDirection(); // no break intentionally - change also the Y dir!!!

	case Board::BallPosition::CENTER_HIT:
		movePC = true;
		ball.changeXDirection();
		break;
	}

}