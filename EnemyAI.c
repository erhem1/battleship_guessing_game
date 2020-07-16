#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GlobalVariables.h"

int ai_x( int difficulty)
{
	int x = 0; 
	srand(time(NULL));
	int ship_number = rand() % 5;
	if( (rand() % 2) == 0 )  // 50% chance to add the random number to middle_position
	{
		while(1)
		{
			if(difficulty == EASY)          x = middle_position[ship_number] + (rand() % 4);
			else if(difficulty == MEDIUM)   x = middle_position[ship_number] + (rand() % 3);
			else if(difficulty == HARD)     x = middle_position[ship_number] + (rand() % 2);
			else return -1; // Not a proper difficulty as argument
			if( ( x>= 0 ) && ( x<100) ) return x;
		}
	}
	else  			// 50% chance to minus the random number from  middle_position 
	{
		while(1)
		{
			if(difficulty == EASY)          x = middle_position[ship_number] - (rand() % 4);
			else if(difficulty == MEDIUM)   x = middle_position[ship_number] - (rand() % 3);
			else if(difficulty == HARD)     x = middle_position[ship_number] - (rand() % 2);
			else return -1; // Not a proper difficulty as argument
			if( ( x>= 0 ) && ( x<100) ) return x;
		}
	}

}

int ai_y(int difficulty)
{
	int y = 0;
	srand(time(NULL));
	int ship_number = rand() % 5;
	if( (rand() % 2) == 0 ) // 50% chance to add the random number to middle_position
	{
		while(1)
		{
			if(difficulty == EASY)         y = middle_position[ship_number] + (rand() % 4);
			else if(difficulty == MEDIUM)  y = middle_position[ship_number] + (rand() % 3);
			else if(difficulty == HARD)    y = middle_position[ship_number] + (rand() % 2);
			else return -1; // Not a proper difficulty as argument
			if( ( y>=0 ) && ( y<100 ) ) return y;
		}
	}
	else			// 50% chance to subtract te random from middle_position   
	{
		while(1)
		{
			if(difficulty == EASY)         y = middle_position[ship_number] - (rand() %4);
			else if(difficulty == MEDIUM)  y = middle_position[ship_number] - (rand() %3);
			else if(difficulty == HARD)    y = middle_position[ship_number] - (rand() %2);
			else return -1; // Not a proper difficulty as argument
			if( ( y>=0 ) && ( y<100 ) ) return y;
		}
	}
}

void buildShips()
{
	for(int i = 0; i<5;i++)
	{
		int xCoordinate = rand() % 9;
		int yCoordinate = rand() % 9; //chooses a random location on the coordinate plane
		do
		{
			if(rand() % 1)
			{
				board
			}	
		}
		while(rand()%1);//chooses wether to continue building or build new ship
	}

}
