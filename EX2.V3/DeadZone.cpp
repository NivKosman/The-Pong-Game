#include"DeadZone.h"

int  DeadZone:: how_much_to_drop(int x_top,int y_top)
{
	int counter = 0;
     x_top = convert_x(x_top);
	while ( (m_Mat[y_top][x_top -  1]  != '#' ) && 
		    (m_Mat[y_top+1][x_top - 1] != '#') &&
		    (m_Mat[y_top+2][x_top - 1] != '#' ) &&
		     x_top>1 )
	{
		
		counter++;
		x_top = x_top-1;
	}
	return counter;
}

BOOL DeadZone::check_clear(int x)
{
	int y;
	x = convert_x(x);
	for (y = 4; y < MAX_Y; y++)
	{
		if (m_Mat[y][x] != '#')
			return false;
	}
	return true;
}

int DeadZone::draw_drop(int x_top, int y_top) 
{
	int count;
	 count = how_much_to_drop(x_top,y_top);
	int i;
	for (i = 0; i < count; i++)
	{
		changeToClear(x_top, y_top);
		changeToClear(x_top, y_top + 1);
		changeToClear(x_top, y_top + 2);
		Sleep(150);
				
		changetofill(x_top- m_side, y_top);
		changetofill(x_top- m_side, y_top + 1);
		changetofill(x_top- m_side, y_top + 2);
		Sleep(150);
		

		
	
		
		x_top= x_top-m_side;

	}
	return x_top;
}

void DeadZone::change_full_line(int x)
{

	int y;
	for (y = MIN_Y; y < MAX_Y; y++)
	{
		changeToClear(x, y);
		Sleep(50);
	}
}

void DeadZone::drop_cause_full_line(int x)
{
	x = convert_x(x);
	int i ,y;
	for (i=x+1; i < MAX_X; i++)
	{
		for (y = MIN_Y; y < MAX_Y; y++)
		{
			if (m_Mat[y][i] == '#')
			{
				changeToClear(i, y);
				Sleep(50);
				changetofill(i - m_side, y);
				Sleep(50);

			}
		}
	}
}

