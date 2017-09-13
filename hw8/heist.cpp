//Christopher Torralba		Section: B
//heist.cpp (hw8)		Date: 4/7/16

#include <iostream>
#include <string>
using namespace std;
int solved = 0;
bool validMove(int checkX, int checkY, char** map);
bool validMove(int checkX, int checkY, char** map)
{
  if((map[checkX][checkY]==' ')||(map[checkX][checkY]=='E'))
  {
  	if (map[checkX][checkY]!='E')
  	  map[checkX][checkY]='.';
    return true;
  }
  else
    return false;
}

void printmap(char**map, int height);
void printmap(char**map, int height)
{
  for (int k =0; k < height; k++)
  {
 	  cout << map[k] << endl;
  }
}

bool move(int baseX, int baseY, char** map, int height);
bool move(int baseX, int baseY, char** map, int height)
{
  int newX;
  int newY;
  int choiceDir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
  //choiceDir[the set][num in the set]
  int choice[4] = {0, 1, 2, 3}; //0 = N, 1 = E, 2 = S, 3 = W
  for (int k = 0; k < 4; k++)
  {
  	newX = baseX + choiceDir[choice[k]][0];
  	newY = baseY + choiceDir[choice[k]][1];
  	if(validMove(newX, newY, map))
  	{
  		if (map[newX][newY]=='E')
  		  return true;
  		else
  		{
  		  bool solve = move(newX,newY,map,height);
  		  //testing purposes: printmap(map,height);
  		  if(solve)
  		  {
  		  	return true;
  		  }
  		  else
  		  {
  		  	map[newX][newY] = ' ';
  		  }
  	  }
  	}
  }
  return false;
}

int main ()
{
  char** maze;
  int width, height, startXPos, startYPos;
  int mapCount=0;
  
  do
	{
		cin >> width >> height;
		if (width == 0 && height == 0)
		{
			return 0;
	  }
    cout << "Map : " << mapCount << endl;
	  mapCount++;
		cin.ignore(1000, '\n');
			  
	  //allocating memory
	  maze = new char*[height];
	  for(int k=0; k < height; k++){
	    maze[k] = new char[width+2];
	  }
	  
	  //writing maze
	  for(int k=0; k < height; k++){	
	    cin.getline(maze[k], width+2);
	  }

	  //maze[row][column] starting from 0 to access.
	  //where position is
	  for (int k=0; k<height;k++)
	  {
	  	for (int j=0;j<width;j++)
	  	{
	  		if (maze[k][j]=='B')
	  		{
	  			startXPos = k;
	  			startYPos = j;
	  		}
	  	}
	  }
	
		if (move(startXPos, startYPos, maze, height))
		{
			printmap(maze,height);
		}
		else
		{
			cout << "failed to locate exit" << endl;
		}
		
	  // De-allocate Maze Array
	  for(int k=0; k < height; k++){
	    delete [] maze[k];
	  }
	  delete [] maze;
	  cout << endl;
	}while (width != 0 && height != 0);
  return 0;
}
