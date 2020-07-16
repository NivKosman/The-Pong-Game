#pragma once
#include "Point.h"

// forward declaration (??)
class Ball;

class Board {
	// object members
	Point top, bottom;
	const int side;// board left=1,board right =(-1)

public: // public enums
	enum class BallPosition { MISSED, CENTER_HIT, CORNER_HIT, AWAY };

public: // public functions
	virtual ~Board() {}

	Board(const Point& left1, const Point& right1, const int& side1) :
	top(left1),bottom(right1),side(side1) {}

	void draw(); 
	
	Point& getTop()  {
		return top;
}
	
	Point& getBottom() {
		return bottom;
	}
	
	const int& getSide(){
		return side;
	}

	int getUpperY()const {
		return top.getY();
	}
	
	int getBottomY()const {
		return bottom.getY();
	}
	
	int getX()const {
		return bottom.getX();
	}
	
	void erase_board()
	{
		Point temp = top;
		do {
			temp.erase();
			temp.setDirection(0, 1);
			temp.move();
			
		} while (temp != bottom);
		temp.erase();
	}
	
	void ChangeBoard_Cause_Lose()
	{
		 bottom.setPoint(bottom.getX() + side, bottom.getY(), '#');
		 top.setPoint(top.getX() + side, top.getY(), '#');
	}
	
	void board_plus5()
	{
		bottom.setPoint(bottom.getX() - side*5, bottom.getY(), '#');
		top.setPoint(top.getX() - side*5, top.getY(), '#');
	}
	
	BallPosition checkBallPosition(const Ball& ball);

	virtual void handleKey(char c) = 0;


};