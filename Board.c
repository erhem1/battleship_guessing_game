#include <stdio.h>
#include "GlobalVariables.h"

void printBoard()
{
	for(int i =0; i<10;i++)
	{
		for(int j=0; j<10;j++)
		{
			printf("%d ",board[i][j]);
			if(i==10)
			{
				printf("\n");
			}
		}
	}
}