#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "EnemyBuild.h"
#include "GlobalVariables.h"

void buildShips()
{
	srand(time(NULL));
	int xCoordinate = rand() % 10;
	int yCoordinate = rand() % 10; //chooses a random location on the coordinate plane

	int xCoorPlus=++xCoordinate;
	int yCoorPlus=++yCoordinate;
	int xCoorMinus=--xCoordinate;
	int yCoorMinus=--yCoordinate; //sets offset from main coordinates in order to expand ship
	bool expandFailed=false;//incase expand is out of bounds
	int shipsBuilt=0; //keeps track of ships built not expansions
	bool shipRotationChosen=false;
	bool shipOrientation;
	int fails=0;
	for(int i = 0; i<5;i++)
	{
		if(!shipRotationChosen)
		{
			shipOrientation= rand() %1;
		}
		shipRotationChosen=true;
		int startSize=0;
		int maxSize=4;
		int shipBuildCondition = canBuild(xCoordinate,yCoordinate);//checks if the space is 											//empty or not
			

		switch(shipBuildCondition)//depending on the condition of the space ship is built
		{
			case 1://space is empty and can be built on
				board[yCoordinate][xCoordinate]=ENEMY;
				printf("\nbuilding new ship\n");
				fails--;
				break;
			case 2: ;//space is already taken by own ship so continue to build onto ship
				int direction = rand() %2;
				printf("\nexpanding ship\n");
				if(shipOrientation)//checks wether to build left/down or right/up
				{
					printf("expanding horizontally");
					printf("1");
					if(direction)
					{
						printf("2");
						if(canBuild(xCoorPlus,yCoordinate)==1)
						{
							printf("3");

							board[yCoordinate][xCoorPlus]=ENEMY;
						
						}
						else
						{
							expandFailed=true;
						}
					}
					else
					{
						printf("2");
						if(canBuild(xCoorMinus,yCoordinate)==1)
						{
							printf("3");
							board[yCoordinate][xCoorMinus]=ENEMY;
							
						}
						else
						{
							expandFailed=true;
						}
					}
				}
				else
				{
					printf("expanding vertically");
					printf("1");
					if(direction)
					{	printf("2");
						if(canBuild(xCoordinate,yCoorPlus)==1)
						{
							printf("3");
							board[yCoorPlus][xCoordinate]=ENEMY;
							
						}
						else
						{
							expandFailed=true;
						}
					}
					else
					{
						printf("2");
						if(canBuild(xCoordinate,yCoorMinus)==1)
						{
							printf("3");
							board[yCoorMinus][xCoordinate]=ENEMY;
						}
						else
						{
							expandFailed=true;
						}
					}
				}
				startSize++;
				if(expandFailed)
				{
					--startSize;
					fails++;
				}
				else
				{
					xCoorPlus++;
					yCoorPlus++;
					xCoorMinus--;
					yCoorMinus--;
					fails--;
					if(fails>0)
					{
						xCoorPlus-=fails;
						yCoorPlus-=fails;
						xCoorMinus+=fails;
						yCoorMinus+=fails;
					}
				}
				--i;
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
			if(fails!=0)
			{
				i!=fails;
				fails=0;
			}
			shipRotationChosen=false;
			xCoordinate = rand() % 10;
			yCoordinate = rand() % 10;
			shipsBuilt++;
		}
		if(shipsBuilt==5)
		{
			break;
		}
	}

}


int canBuild(int xCoor,int yCoor)
{
		if(board[yCoor][xCoor]==EMPTY&&board[yCoor][xCoor]!=ENEMY) //sea is empty
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
