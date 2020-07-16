#include <stdio.h>
#include <stdbool.h>
#include "EnemyBuild.h"
#include "GlobalVariables.h"

void buildShips()
{
	for(int i = 0; i<5;i++)
	{
		bool cantBuild=false;
		int xCoordinate = rand() % 9;
		int yCoordinate = rand() % 9; //chooses a random location on the coordinate plane
		bool shipOrientation= rand() %1;

		if(cantBuild&& i==1)
		{
			i=0;
			cantBuild=false;
		}

			do{
				int startSize=0;
				int maxSize=4;
				int shipBuildCondition = canBuild(xCoordinate,yCoordinate);//checks if the space is 
												//empty or not
				
				switch(shipBuildCondition)//depending on the condition of the space ship is built
							//on the location
				{
					case 1://space is empty and can be built on
						board[yCoordinate,xCoordinate]=ENEMY;
						break;
					case 2://space is already taken by own ship so continue to build onto ship
						bool direction = rand() %1;
						if(direction)//checks wether to build left/down or right/up
						{
							if(shipOrientation)
							{
								if(canBuild(xCoordinate+1,yCooridnate)==2)
								{
								board[yCoordinate,xCoordinate+1]=ENEMY;
								}	
							}
							else
							{
								if(canBuild(xCoordinate,yCooridnate+1)==2)
								{
								board[yCoordinate+1,xCoordinate]=ENEMY;
								}
							}
						}
						else
						{
							if(shipOrientation)
							{
								if(canBuild(xCoordinate-1,yCooridnate)==2)
								{
									board[yCoordinate,xCoordinate-1]=ENEMY;
								}
							}
							else
							{
								if(canBuild(xCoordinate,yCooridnate-1)==2)
								{
								board[yCoordinate-1,xCoordinate]=ENEMY;
								}
							}
						}
						break;
					case 0:
						if(i==0)
						{
							cantBuild=true;
						}
						else
						{
							--i;
						}
						break;

				}


				if(startSize==maxSize)
				{
					break;
				}
				int expand = rand() %1;
				if(expand)
				{
					++i;
				}
			}while(expand);//chooses wether to continue building or build new ship
			xCoordinate = rand() %9;
			yCoordinate = rand() %9;
		
	}

}

int canBuild(int xCoor,int yCoor)
{
	if(!xCoor<0 && !xCoor>10 && !yCoor<0 && !yCoor>10)
	{
		if(board[yCoor,xCoor]!=FRIENDLY&& board[yCoor,xCoor]!=ENEMY) //sea is empty
		{
			return 1;
		}
		else if(board[yCoord,xCoor]==ENEMY)//ship already built
		{
			return 2;
		}
		else//can't build
		{
			return 0;
		}
	}
}
