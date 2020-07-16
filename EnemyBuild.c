void buildShips()
{
	for(int i = 0; i<5;i++)
	{
		int xCoordinate = rand() % 9;
		int yCoordinate = rand() % 9; //chooses a random location on the coordinate plane
		bool shipOrientation= rand() %1;
		if(shipOrientation)//chooses the orientation of the ship. in which one is horizontal
		{
			do{
				int startSize=0;
				int maxSize=4;
				int shipBuildCondition = canBuild(xCoordinate,yCoordinate);//checks if the space is 
												//empty or not
				
				switch(shipBuildCondition)//depending on the condition of the space ship is built
							//on the location
				{
					case 1://space is empty and can be built on
						board[yCoordinate,xCoordinate]=ENEMYSHIP;
						break;
					case 2://space is already taken by own ship so continue to build onto ship
						bool direction = rand() %1;
						if(direction)//checks wether to build left or right
						{
							if(canBuild(xCoordinate+1,yCooridnate)==2)
							{
								board[yCoordinate,xCoordinate]==ENEMYSHIP;
							}
						}
						break;
					case 0:

				}


				if(startSize==maxSize)
				{
					break;
				}
			}while(rand()%1);//chooses wether to continue building or build new ship
			xCoordinate = rand() %9;
			yCoordinate = rand() %9;

		}
		else
		{

		}
		
	}

}

int canBuild(int xCoor,int yCoor)
{
	if(!xCoor<0 && !xCoor>10 && !yCoor<0 && !yCoor>10)
	{
		if(board[yCoor,xCoor]!=FRIENDLY&& board[yCoor,xCoor]!=ENEMY)
		{
			return 1;
		}
		else if(board[yCoord,xCoor]==ENEMY)
		{
			return 2;
		}
		else
		{
			return 0;
		}
	}
}
