#pragma once
#include "Board.h"
#include "Ball.h"

class PCboard :public Board {
	enum  difficulty { NOVICE, GOOD, BEST };
private:
	int counter = 0;
	enum  { UP, DOWN };
	int *dif;
	Ball *pBall;

public:
	PCboard(const Point& left1, const Point& right1, const int& side1, int *dif1, Ball *ball ) :
		Board(left1, right1, side1), dif(dif1), pBall(ball){}
	
	int how_much_to_move(const int& ball_y);

	void Set_Counter()
	{
		counter = 0;
	}
	
	int& Get_counter() {
		return counter;
	}
	
	int calculate_Y(const Point& ball);
	
	void move_board_down();
	
	void move_board_up();

	virtual void handleKey(char c);
	
	int rand_lose();

	void move_to_lose();

	/*void setDifficulty(char c) {
		if (c - '1' == NOVICE)
			dif = NOVICE;
		if (c - '2' == GOOD)
			dif = GOOD;
		if (c - '3' == BEST)
			dif = BEST;
	}*/
};