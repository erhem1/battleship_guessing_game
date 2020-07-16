#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Board.h"
#include "GlobalVariables.h"
#include "EnemyAI.h"
#include "EnemyBuild.h"
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
struct twoDArray {
	int positions[2][5];
};
struct twoDArray build_player_ships();

int main(void)
{
	int difficulty;
	while(true)
	{
		printf("Choose a difficulty \n1.EASY\n2.MEDIUM\n3.HARD\nDIFFICULTY:");
		scanf("%d",&difficulty);
		if(difficulty!=1 && difficulty!=2 && difficulty!=3)
		{
			printf("Choose a valid difficulty\n");
		}
		else break;
	}
	buildShips();
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
			if(enemyAI_choose_coordinates(difficulty))
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
	return false;
}

bool enemyAI_choose_coordinates(int difficulty)
{
	struct twoDArray placement; 
	placement = build_player_ships();
	int middle_positions[2][5]; 
	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<5 ; i++)
		{
			middle_positions[i][j] = placement.positions[i][j];
		}
	}	
	int random_y = middle_positions[0][rand() % 5];
	int random_x = middle_positions[1][rand() % 5];

	int firing_y = ai_y(random_y, difficulty);
	int firing_x = ai_x(random_x, difficulty);
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
	return false;
}


struct twoDArray build_player_ships()  // Intializes player ships when first used. Afterwards is used to return middle_positions. Considers int counter to determine whether to initialize or not.
{
	int middle_positions[2][5];	
	static struct twoDArray placement;
	int x, y;
	int counter = 0;
	if(counter ==0)
	{
		for(int i = 0; i<5; i++)
		{
			while(true)
			{
				int y = (rand() % 40) + 60;
				int x = rand() % 100;
				if(y == EMPTY && x == EMPTY) break;
			}
			middle_positions[0][i] = y; //Assign middle_position for later use 0 is y
			middle_positions[1][i] = x; //Assign middle_position for later use 1 is x 
				
			board[y][x] == FRIENDLY;
			if(rand()%2 == 1) // Vertical Allignment
			{
				if(rand()%2 == 1)  // Up
				{
					for(int j = 1; j<= ((rand()%4)+1) ; j++)
					{
						if(board[y-j][x] == EMPTY) board[y-j][x] = FRIENDLY;
						else break;
					}
				}
				else   		   // Down
				{
					for(int j = 1; j<= ((rand()%4)+1) ; j++)
					{
						if(board[y+j][x] == EMPTY) board[y+j][x] = FRIENDLY;
						else break;
					}
				}
			}
			else  	   // Horizontal Allignment		
			{
				if(rand()%2 == 1) // Left 	
				{
					for(int j = 1; j<= ((rand()%4)+1) ; j++)
					{
						if(board[y][x-j] == EMPTY) board[y][x-j] = FRIENDLY;
						else break;
					}	
				}
				else		  // Right 
				{
					for(int j = 1; j<= ((rand()%4)+1) ; j++)
					{
						if(board[y][x+j] == EMPTY) board[y][x+j] = FRIENDLY;
						else break;
					}

				}
			}
		}

		for(int i = 0; i<2; i++)
		{
			for(int j = 0; i<5 ; j++)
			{
				placement.positions[i][j] = middle_positions[i][j];
			}
		}
		counter++;
	}
	
	return placement; 
}

