#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GlobalVariables.h"

int ai_x(int middle_position, int difficulty)
{
	int x = 0; 
	srand(time(NULL));
	while(1)
	{
		if(difficulty == EASY)          x = rand() % 4;
		else if(difficulty == MEDIUM)   x = rand() % 3;
		else if(difficulty == HARD)     x = rand() % 2;
		else continue;
		if( ( x>= 0 ) && ( x<100) ) return x;
	}

}

int ai_y(int middle_position, int difficulty)
{
	int y = 0;
	srand(time(NULL));
	while(1)
	{
		if(difficulty == EASY)         y = rand() % 4;
		else if(difficulty == MEDIUM)  y = rand() % 3;
		else if(difficulty == HARD)    y = rand() %2;
		else continue;
		if( ( y>=0 ) && ( y<100 ) ) return y;
	}
}


