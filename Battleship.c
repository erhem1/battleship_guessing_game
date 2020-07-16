#include <stdio.h>
#include "Board.h"
#include <stdbool.h>
#include "GlobalVariables.h"
int board[10][10] = {
	{ EMPTY, EMPTY , EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY , EMPTY, EMPTY},
	{ EMPTY, EMPTY , EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY , EMPTY, EMPTY},
	{ EMPTY, EMPTY , EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY , EMPTY, EMPTY},
	{ EMPTY, EMPTY , EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY , EMPTY, EMPTY},
	{ EMPTY, EMPTY , EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY , EMPTY, EMPTY},
	{ EMPTY, EMPTY , EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY , EMPTY, EMPTY},
	{ EMPTY, EMPTY , EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY , EMPTY, EMPTY},
	{ EMPTY, EMPTY , EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY , EMPTY, EMPTY},
	{ EMPTY, EMPTY , EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY , EMPTY, EMPTY},
	{ EMPTY, EMPTY , EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY , EMPTY, EMPTY}
	};

bool friendly_player_choose_coordinates();
bool enemyAI_choose_coordinates();

int main(void)
{
	int cycle = 1;	
	while(1)
	{
		if(cycle)
		{
		 	printBoard();
			if(friendly_player_choose_coordinates()) cycle = 0;	
		}		
		else
		{
			printBoard();
			if(enemyAI_choose_coordinates()) cycle = 1;
		}
		
	}
	return 0;
}

bool friendly_player_choose_coordinates(void)
{
	int firing_y;
	int firing_x;
	printf("Choose a x:");
	scanf("%d", &firing_x);
	printf("Choose a y:");
	scanf("%d", &firing_y);
	switch(board[firing_y][firing_x])
	{
		case EMPTY:
		case DESTROYED:
			return true;
		case FRIENDLY:
			printf("Can't fire at friendly unit \n");
			return false;
		case ENEMY: 
			board[firing_y][firing_x] == DESTROYED;
			return true;
		default: 
			return false;
	}
}

bool enemyAI_choose_coordinates(void)
{
	return true;	
}


