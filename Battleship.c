#include <stdio.h>
#include "Board.h"
#include <stdbool.h>
#include "GlobalVariables.h"
#include "EnemyAI.h"
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
	int cycle = true;	
	printBoard();
	while(true)
	{
		if(cycle)
		{
			if(friendly_player_choose_coordinates()) 
			{
				
				cycle = false;	
				printBoard();
			}
		}		
		else
		{
			printf("Bot's turn\n");
			if(enemyAI_choose_coordinates())
			{	
				cycle = true;
				printBoard();
			}

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
			printf("fired at empty land\n");
			return true;
		case DESTROYED:
			printf("fired at already destroyed ship\n");
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
	return false
}

bool enemyAI_choose_coordinates(void)
{
	int firing_y = ai_y();
	int firing_x = ai_x();
	switch(board[firing_y][firing_x])
	{
		case EMPTY: 
			return true;
		case DESTROYED:
			return true;
		case FRIENDLY:
			board[firing_y][firing_x] == DESTROYED;
			return true;
		case ENEMY:
			return false;
		default:
			return false;	
	}		
	return false
}



