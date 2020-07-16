#include "PCBoard.h"

int PCboard::how_much_to_move(const int& ball_y) {
	return  (ball_y - (getUpperY() + 1));
}
	
int PCboard::calculate_Y(const Point& ball)
{
	Point temp(ball);
	while (temp.getX() != this->getX())
	{
		if ((temp.getX() - this->getX() == 1) || (temp.getX() - this->getX() == -1))
			return temp.getY();
		if (temp.getX() + temp.getXDirection() > FIELD_MAX_X || temp.getX() + temp.getXDirection() < FIELD_MIN_X) {
			temp.changeXDirection();
		}
		if (temp.getY() + temp.getYDirection() > FIELD_MAX_Y || temp.getY() + temp.getYDirection() < FIELD_MIN_Y) {
			temp.changeYDirection();
		}
		temp.move();
	}
}

void PCboard::move_board_up()
{
	getBottom().erase();
	getBottom().setDirection(0, -1);
	getTop().setDirection(0, -1);
	getBottom().move();
	getTop().move();
	getTop().draw();
}

void PCboard::move_board_down()
{
	getTop().erase();
	getBottom().setDirection(0, 1);
	getTop().setDirection(0, 1);
	getBottom().move();
	getTop().move();
	getBottom().draw();
}

void PCboard::handleKey(char c){

	int cal = calculate_Y(pBall->getPoint());
	int how = how_much_to_move(cal);
	int i;

		if (how < 0) {
			how = -how;
			for (i = 0; i < how && (getUpperY() > FIELD_MIN_Y); i++) {
				move_board_up();
				Sleep(80);
				pBall->moveBall();
				Sleep(80);
			}
		}
		else if (how > 0) {
			for (i = 0; i < how && (getBottomY() < FIELD_MAX_Y); i++) {
				move_board_down();
				Sleep(80);
				pBall->moveBall();
				Sleep(80);
			}
		}
		counter++;

}

int PCboard::rand_lose()
{
	if (*dif == GOOD)
		return rand() % 40;
	if (*dif == NOVICE)
		return rand() % 10;
	if (*dif == BEST)
		return -1;
}

void PCboard::move_to_lose()
{
	int cal = calculate_Y(pBall->getPoint());
	if (cal <= 19) {
		this->handleKey('c');
		for (int i = 0; i <= 4; i++){
			this->move_board_down();
			//Sleep(80);
	       }
	}
	else
	{
		this->handleKey('c');
		for (int i = 0; i <= 4; i++) {
			this->move_board_up();
			//Sleep(80);
		}
	}
	counter = 0;
}

