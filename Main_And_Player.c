#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include "Board.h"
#include "GlobalVariables.h"
#include "EnemyAI.h"
#include "EnemyBuild.h"
#include "twoDStructure.h"
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
	int count_of_enemy_ships = buildShips();
	int* countptr_of_enemy_ships = &count_of_enemy_ships;

	struct twoDArray structure_main = build_player_ships();
	int count_of_friendly_ships = structure_main.count_of_ships;
	int* countptr_of_friendly_ships = &count_of_friendly_ships;
	
	int cycle = true;	
	printBoard();
	while(true)
	{
		if(count_of_friendly_ships == 0)
		{
			printf("AI won\n");
			break;
		}
		if(count_of_enemy_ships == 0)
		{
			printf("Player won\n");
			break;
		}
		if(cycle)
		{
			if(friendly_player_choose_coordinates(countptr_of_enemy_ships)) 
			{
				
				cycle = false;	
				sleep(1);
				printBoard();
			}
		}		
		else
		{
			printf("Bot's turn\n");
			if(enemyAI_choose_coordinates(difficulty, countptr_of_friendly_ships, structure_main))
			{	
				cycle = true;
				printBoard();
				printf("Friendly Ships Remaining: %d /n Enemy Ships Remaining: %d \n", count_of_friendly_ships, count_of_enemy_ships);
			}

		}
		
	}
	return 0;
}

bool friendly_player_choose_coordinates(int* countptr_of_enemy_ships)
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
		case ENEMYDESTROYED:
			printf("fired at already destroyed ship\n");
			return true;
		case FRIENDLY:
			printf("Can't fire at friendly unit \n");
			return false;
		case ENEMY: 
			board[firing_y][firing_x] = ENEMYDESTROYED;
			(*countptr_of_enemy_ships)--;
			printf("Fired enemy ship\n");
			return true;
		default: 
			return false;
	}
	return false;
}



struct twoDArray build_player_ships()  // Intializes player ships when first used. Afterwards is used to return middle_positions. Considers int counter to determine whether to initialize or not.
{
	int count_of_ships = 0;
	int middle_positions[2][5];	
	static struct twoDArray placement;
	int x, y;
	for(int i = 0; i<5; i++)
	{
		while(true)
		{
			y = (rand() % 4) + 6;
			x = rand() % 10;
			if(board[y][x]==EMPTY) break;
		}
		middle_positions[0][i] = y; //Assign middle_position for later use 0 is y
		printf("%d,%d,%d\n", middle_positions[0][i], y, x);
		middle_positions[1][i] = x; //Assign middle_position for later use 1 is x 
		printf("%d,%d\n", middle_positions[0][i], middle_positions[1][i]);	
		board[y][x] = FRIENDLY;
		if((rand()%2) == 1) // Vertical Allignment
		{
			if((rand()%2) == 1)  // Up
			{
				for(int j = 1; j<= ((rand()%4)+1) ; j++)
				{
					switch(board[y-j][x])
					{
						case EMPTY: 
							board[y-j][x] = FRIENDLY;
							count_of_ships++;
						case FRIENDLY:
							continue;
						default: 
							break;
					}	
				}
			}
			else   		   // Down
			{
				for(int j = 1; j<= ((rand()%4)+1) ; j++)
				{
					switch(board[y+j][x])
					{
						case EMPTY: 
							board[y+j][x] = FRIENDLY;
							count_of_ships++;
						case FRIENDLY:
							continue;
						default:
							break;
					}
				}
			}
		}
		else  	   // Horizontal Allignment		
		{
			if((rand()%2) == 1) // Left 	
			{
				for(int j = 1; j<= ((rand()%4)+1) ; j++)
				{
					switch(board[y][x-j])
					{
						case EMPTY:
							board[y][x-j] = FRIENDLY;
							count_of_ships++;
						case FRIENDLY:
							continue;
						default:
							break;
					}
				}	
			}
			else		  // Right 
			{
				for(int j = 1; j<= ((rand()%4)+1) ; j++)
				{
					switch(board[y][x+j])
					{
						case EMPTY:
							board[y][x+j] = FRIENDLY;
							count_of_ships++;
						case FRIENDLY:
							continue;
						default:
							break;

					}
				}

			}
		}
	}

	for(int i = 0; i<2; i++)
	{
		for(int j = 0; j<5 ; j++)
		{
			placement.positions[i][j] = middle_positions[i][j];
		}
	}
	placement.count_of_ships = count_of_ships;
	return placement; 
}

