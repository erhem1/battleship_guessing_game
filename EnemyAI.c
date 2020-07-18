#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "GlobalVariables.h"
#include "twoDStructure.h"
bool enemyAI_choose_coordinates();
int ai_x(int middle_position, int difficulty);
int ai_y(int middle_position, int difficulty);

bool enemyAI_choose_coordinates(int difficulty, struct twoDArray structure_main)
{
	int random_number = rand()%5;
	int random_y = structure_main.positions[0][random_number];
	int random_x = structure_main.positions[1][random_number];

	int firing_y = ai_y(random_y, difficulty);
	int firing_x = ai_x(random_x, difficulty);
	switch(board[firing_y][firing_x])
	{
		case FRIENDLY:
			board[firing_y][firing_x] = DESTROYED;
			printf("Bot hits player's ship at (%d,%d)\n\n",firing_x,firing_y);
			return true;
		default:
			printf("Bot misses. Bot Attack Coordinates: (%d,%d)\n\n",firing_x,firing_y);
			return true;	
	}		
	return false;
}

int ai_x(int middle_position_x , int difficulty)
{
	int x = 0; 
	srand(time(NULL));
	if( (rand() % 2) == 0 )  // 50% chance to add the random number to middle_position
	{
		while(1)
		{
			if(difficulty == EASY)          x = middle_position_x + (rand() % 4);
			else if(difficulty == MEDIUM)   x = middle_position_x + (rand() % 3);
			else if(difficulty == HARD)     x = middle_position_x + (rand() % 2);
			else return -1; // Not a proper difficulty as argument
			if( ( x>= 0 ) && ( x<100) ) return x;
		}
	}
	else  			// 50% chance to minus the random number from  middle_position 
	{
		while(1)
		{
			if(difficulty == EASY)          x = middle_position_x - (rand() % 4);
			else if(difficulty == MEDIUM)   x = middle_position_x - (rand() % 3);
			else if(difficulty == HARD)     x = middle_position_x - (rand() % 2);
			else return -1; // Not a proper difficulty as argument
			if( ( x>= 0 ) && ( x<100) ) return x;
		}
	}

}

int ai_y(int middle_position_y, int difficulty)
{
	int y = 0;
	srand(time(NULL));
	int ship_number = rand() % 5;
	if( (rand() % 2) == 0 ) // 50% chance to add the random number to middle_position
	{
		while(1)
		{
			if(difficulty == EASY)         y = middle_position_y + (rand() % 4);
			else if(difficulty == MEDIUM)  y = middle_position_y + (rand() % 3);
			else if(difficulty == HARD)    y = middle_position_y + (rand() % 2);
			else return -1; // Not a proper difficulty as argument
			if( ( y>=0 ) && ( y<100 ) ) return y;
		}
	}
	else			// 50% chance to subtract te random from middle_position   
	{
		while(1)
		{
			if(difficulty == EASY)         y = middle_position_y - (rand() %4);
			else if(difficulty == MEDIUM)  y = middle_position_y - (rand() %3);
			else if(difficulty == HARD)    y = middle_position_y - (rand() %2);
			else return -1; // Not a proper difficulty as argument
			if( ( y>=0 ) && ( y<100 ) ) return y;
		}
	}
}


