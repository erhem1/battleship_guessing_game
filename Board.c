#include <stdio.h>
#include "GlobalVariables.h"

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define BLUE  "\x1b[34m"
#define COLORRESET "\x1b[0m"
#define SEA "#"
#define SHIP "@"
#define ENEMYSHIP "%"

void printBoard()
{
	for(int i =0; i<=11;i++)
	{
		for(int j=0; j<11;j++)
		{
			switch(board[i][j])
			{
				case EMPTY:
					printf(BLUE"%s"COLORRESET,SEA);
					break;
				default:
					break;
					
			}
			if(j==10)
			{
				printf("\n");
			}
		}
	}
}
