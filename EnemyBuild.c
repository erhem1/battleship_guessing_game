#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "EnemyBuild.h"
#include "GlobalVariables.h"

void buildShips()
{
	int xCoordinate = rand() % 10;
	int yCoordinate = rand() % 10; //chooses a random location on the coordinate plane

	for(int i = 0; i<5;i++)
	{
		bool shipOrientation= rand() %1;
		int startSize=0;
		int maxSize=4;
		int shipBuildCondition = canBuild(xCoordinate,yCoordinate);//checks if the space is 											//empty or not
		int xCoorPlus=++xCoordinate;
		int yCoorPlus=++yCoordinate;
		int xCoorMinus=--xCoordinate;
		int yCoorMinus=--yCoordinate;
		printf("\ncoordinates  x%d y%d\n",xCoordinate,yCoordinate);

		switch(shipBuildCondition)//depending on the condition of the space ship is built
		{
			case 1://space is empty and can be built on
				board[yCoordinate][xCoordinate]=ENEMY;
				break;
			case 2: ;//space is already taken by own ship so continue to build onto ship
				printf("big ship success\n");
				int direction = rand() %2;
				if(direction)//checks wether to build left/down or right/up
				{
					if(shipOrientation)
					{
						if(canBuild(xCoorPlus,yCoordinate)==2)
						{
							board[yCoordinate][xCoorPlus]=ENEMY;
							xCoorPlus++;
						}	
					}
					else
					{
					if(canBuild(xCoorMinus,yCoordinate)==2)
					{
					board[yCoordinate][xCoorMinus]=ENEMY;
					xCoorMinus--;
					}
					}
				}
				else
				{
					if(shipOrientation)
					{
						if(canBuild(xCoordinate,yCoorPlus)==2)
						{
							board[yCoorPlus][xCoordinate]=ENEMY;
							yCoorPlus++;
						}
					}
					else
					{
						if(canBuild(xCoordinate,yCoorMinus)==2)
						{
						board[yCoorMinus][xCoordinate]=ENEMY;
						yCoorMinus--;
						}
					}
				}
				startSize++;
				break;
			case 0:
			break;
		}
		if(startSize==maxSize)
		{
			break;
		}
		if(rand()%2)
		{
			xCoordinate = rand() % 10;
			yCoordinate = rand() % 10;
		}
		else
		{

		}

	}


				
}

int canBuild(int xCoor,int yCoor)
{
		if(board[yCoor][xCoor]==EMPTY) //sea is empty
		{
			return 1;
		}
		else if(board[yCoor][xCoor]==ENEMY)//ship already built
		{
			return 2;
		}
		else//can't build
		{
			return 0;
		}
}
