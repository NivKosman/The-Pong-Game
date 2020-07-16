#pragma once
#include "Point.h"

//class Point;
using namespace std;

class Ball {
	enum {BALL_SIZE = 1}; // TODO: change and use when shaping ball in the future

private:
	Point m_ballP = { 40, 18, 'O' };
	int def_x,
		def_y;

public:
	Ball() {}
	void set( Point&  center);

	int getX()const {
		return m_ballP.getX();
	}
	
	Point getPoint()const {
		return m_ballP;
	}
	
	int getY()const {
		return m_ballP.getY();
	}

	int getXDirection()const {
		return m_ballP.getXDirection();
	}

	int getYDirection()const {
		return m_ballP.getYDirection();
	}

	void changeYDirection() {
		m_ballP.changeYDirection();
	}

	void changeXDirection() {
		m_ballP.changeXDirection();
	}

	void moveBall();

	void eraseball()
	{
		m_ballP.draw(' ');
	}

	void reset() {
		m_ballP.setPoint(40, 18, 'O');
	}
	void Rand_dir();
};