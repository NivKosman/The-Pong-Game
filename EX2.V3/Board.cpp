#include "utils.h"
#include "Board.h"
#include "Ball.h"

void Board::draw()
{
	Point temp = top;
	temp.draw();
	do {
		temp.setDirection(0, 1);
		temp.move();
		temp.draw();
	} while (temp != bottom);

}



Board::BallPosition Board::checkBallPosition(const Ball & ball)
{
	// MISSED, CENTER_HIT, CORNER_HIT, AWAY
	int x_dist = (ball.getX() - this->getX())*(this->side);
	if (x_dist <= 0) {
		return BallPosition::MISSED;

	}
	if (x_dist == 1) {
		if (getUpperY() <= ball.getY() && getBottomY() >= ball.getY()) {
			return BallPosition::CENTER_HIT;
		}
		//TODO change directions get to enums
		else if (ball.getY() == (getUpperY() - 1) && ball.getXDirection() == -1
			|| ball.getX() == (getBottomY() + 1) && ball.getXDirection() == 1) {
			return BallPosition::CORNER_HIT;
		}
	}
	return BallPosition::AWAY;
}
