#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ai_x(int middle_position, int difficulty)
{
	int x = 0; 
	srand(time(NULL));
	if( (rand() % 2) == 0 )  // 50% chance to add the random number to middle_position
	{
		while(1)
		{
			if(difficulty == EASY)          x = middle_position + (rand() % 4);
			else if(difficulty == MEDIUM)   x = middle_position + (rand() % 3);
			else if(difficulty == HARD)     x = middle_position + (rand() % 2);
			else return -1; // Not a proper difficulty as argument
			if( ( x>= 0 ) && ( x<100) ) return x;
		}
	}
	else  			// 50% chance to minus the random number from  middle_position 
	{
		while(1)
		{
			if(difficulty == EASY)          x = middle_position - (rand() % 4);
			else if(difficulty == MEDIUM)   x = middle_position - (rand() % 3);
			else if(difficulty == HARD)     x = middle_position - (rand() % 2);
			else return -1; // Not a proper difficulty as argument
			if( ( x>= 0 ) && ( x<100) ) return x;
		}
	}

}

int ai_y(int middle_position, int difficulty)
{
	int y = 0;
	srand(time(NULL));
	if( (rand() % 2) == 0 ) // 50% chance to add the random number to middle_position
	{
		while(1)
		{
			if(difficulty == EASY)         y = middle_position + (rand() % 4);
			else if(difficulty == MEDIUM)  y = middle_position + (rand() % 3);
			else if(difficulty == HARD)    y = middle_position + (rand() % 2);
			else return -1; // Not a proper difficulty as argument
			if( ( y>=0 ) && ( y<100 ) ) return y;
		}
	}
	else			// 50% chance to subtract te random from middle_position   
	{
		while(1)
		{
			if(difficulty == EASY)         y = middle_position - (rand() %4);
			else if(difficulty == MEDIUM)  y = middle_position - (rand() %3);
			else if(difficulty == HARD)    y = middle_position - (rand() %2);
			else return -1; // Not a proper difficulty as argument
			if( ( y>=0 ) && ( y<100 ) ) return y;
		}
	}
}


