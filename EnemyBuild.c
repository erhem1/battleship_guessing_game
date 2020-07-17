#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "EnemyBuild.h"
#include "GlobalVariables.h"

enum BuildState{BUILD=1,EXPAND,ERROR};
bool shipBuilt =false;

void buildShips()
{	
	srand(time(NULL));
	int xCoordinate = rand() % 5;
	int yCoordinate = rand() % 5; //chooses a random location on the coordinate plane

	int xCoorPlus=++xCoordinate;
	int yCoorPlus=++yCoordinate;
	int xCoorMinus=--xCoordinate;
	int yCoorMinus=--yCoordinate; //sets offset from main coordinates in order to expand ship
	bool shipRotationChosen=false;
	bool shipOrientation;
	bool expandFailed=false;
	int buildDirection=0;
	for(int i = 0; i<5;i++)
	{
		printf("\n cycles:%d\n",i);
		if(!shipRotationChosen)
		{
			shipOrientation= rand() %1;
		}
		shipRotationChosen=true;
		int shipBuildCondition = canBuild(xCoordinate,yCoordinate);//checks if the space is 
										//empty or not
		switch(shipBuildCondition)//depending on the condition of the space ship is built
		{
			case BUILD://space is empty and can be built on	
				board[yCoordinate][xCoordinate]=ENEMY;
				shipBuilt=true;
				break;
			case EXPAND: ; //space is already taken by own ship so continue to build onto ship
				if(shipBuilt)
				{
			
				int expansionSize=(rand() % 3)+1;
				for(int j=0;j<expansionSize;j++)
				{
					int direction = rand() %2;
					if(shipOrientation)//checks wether to build left/down or right/up
					{
						printf("1");
						if(direction||buildDirection<0)
						{
							printf("2");
							if(canBuild(xCoorPlus,yCoordinate)==EMPTY&&
									canBuild(xCoordinate,yCoordinate)==EXPAND)
							{
								printf("3");
								board[yCoordinate][xCoorPlus]=FRIENDLY;
								++buildDirection;
								expandFailed=false;
							}
							else
							{
								expandFailed=true;
							
							}
						}
						else
						{
							printf("2");
							if(canBuild(xCoorMinus,yCoordinate)==EMPTY&&
									canBuild(xCoordinate,yCoordinate)==EXPAND)
							{
								printf("3");
								board[yCoordinate][xCoorMinus]=FRIENDLY;
								--buildDirection;
								expandFailed=false;
							}
							else
							{
								expandFailed=true;
															break;

							}
						}
					}
					else
					{
						printf("1");
						if(direction||buildDirection<0)
						{	printf("2");
							if(canBuild(xCoordinate,yCoorPlus)==EMPTY &&
									canBuild(xCoordinate,yCoordinate)==EXPAND)
							{
								printf("3");
								board[yCoorPlus][xCoordinate]=FRIENDLY;
								++buildDirection;
								expandFailed=false;
							}
							else
							{
								expandFailed=true;
															break;
							
							}	
						}
						else
						{
							printf("2");
							if(canBuild(xCoordinate,yCoorMinus)==EMPTY &&
									canBuild(xCoordinate,yCoordinate)==EXPAND)
						       	{
								printf("3");
								board[yCoorMinus][xCoordinate]=FRIENDLY;
								--buildDirection;
								expandFailed=false;
							}
							else
							{
								expandFailed=true;
															break;
							}
						}
					}
				}

				if(expandFailed)
				{
					xCoordinate = rand() % 5;
					yCoordinate = rand() % 5;
					xCoorPlus=++xCoordinate;
					yCoorPlus=++yCoordinate;
					xCoorMinus=--xCoordinate;
					yCoorMinus=--yCoordinate;
				       	shipRotationChosen=false;
					shipBuilt=false;
				
				}
			
				--i;
				}
				break;
			case ERROR:	
				break;
		}
	}
}


int canBuild(int xCoor,int yCoor)
{
		if(board[yCoor][xCoor]==EMPTY&&board[yCoor][xCoor]!=ENEMY) //sea is empty
		{
			return BUILD;
		}
		else if(board[yCoor][xCoor]==ENEMY)//ship already built
		{
			return EXPAND;
		}
		else//can't build
		{
			return ERROR;
		}
}
