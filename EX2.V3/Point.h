#pragma once
#include <iostream>
#include "Field.h"
#include "utils.h"

using namespace std;

class Point {
private:
	int x, y;
	int dir_x = 1; 
	int dir_y = 1;
	char ch;

public:
	Point(int x1, int y1, char c) : x(x1), y(y1), ch(c) {}
	Point() {}
	/*Point& operator =(const Point& P){
		if (&P != this)
		{
			x = P.getX();
			y = P.getY();
			dir_x = P.getXDirection();
			dir_y = P.getYDirection();
			ch = P.getChar();

		}
		return *this;
	}*/
	char getChar()const {
		return ch;
	}

	int getX()const {
		return x; 
	}
	
	int getY()const { 
		return y; 
	}

	int getXDirection()const {
		return dir_x;
	}

	int getYDirection()const {
		return dir_y;
	}

	void changeYDirection() {
		this->dir_y *= -1;
	}

	void changeXDirection() {
		this->dir_x *= -1;
	}

	void setPoint(int x, int y, char ch) {
		this->x = x;
		this->y = y;
		this->ch = ch;
	}

	void setDirection(int dir_x, int dir_y) {
		this->dir_x = dir_x;
		this->dir_y = dir_y;
	}
	void setDirX(int x)
	{
		this->dir_x = x;
	}
	void move() {
		
		x += dir_x;
		y += dir_y;
	} 
	
	void erase() {
		draw(' ');
	}

	void draw(char c) {
		field.setCharInField(x, y, c);
	}

	void draw() {
		draw(ch);
	}

	bool operator!=(const Point& other) const {
		return x != other.x || y != other.y;
	}

};
