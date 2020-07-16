#pragma once
#include <iostream>
#include "Point.h"
#include "ConsoleColor.h"

using namespace std;
class DeadZone {
public:	
	enum { MAX_X = 20, MAX_Y = 25, MIN_Y=4 };

private:
	char m_Mat[MAX_Y][MAX_X] = {};
	const int& m_side;//left= 1 ||right = -1
	

public:
	DeadZone(const int& side) :m_side(side){}

	int  how_much_to_drop(int,int);
	
	int convert_x(int x1)
	{
		if (m_side == -1)
			return ( 80 - x1);
		return x1;
	}
	
	int draw_drop(int, int); 
	
	BOOL check_clear(int x);
	
	void change_full_line(int x);
	
	void drop_cause_full_line(int x);

	

private:
	void changetofill(int x, int y)
	{
		x = convert_x(x);
		if (m_side == -1)
		{
			gotoxy(80 - x, y);
			cout << color(FOREGROUND_RED | FOREGROUND_GREEN) << '#';
		}
		else {
			gotoxy(x, y);
			cout << color(FOREGROUND_RED | FOREGROUND_GREEN) << '#';
		}
		m_Mat[y][x] = '#';

	}
	
	void changeToClear(int x, int y)
	{
		x = convert_x(x);
		if (m_side == -1)
		{
			gotoxy(80 - x, y);
			cout << ' ';
		}
		else {
			gotoxy(x, y);
			cout << ' ';
		}
		m_Mat[y][x] = ' ';

	}

};