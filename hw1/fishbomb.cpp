//Christopher Torralba
//Section: B

#include <iostream>
using namespace std;

int main()
{
  short testCases, width, height, bombWidth, bombHeight;
  int **grid;
  int fishCaught, mostFish;
  
  cin >> testCases;
  
  for (short k = 0; k < testCases; k++)
  {
    cin >> width;
    cin >> height;
    
    //allocating 2D array
    grid = new int*[height];
    for (int i = 0; i < height; i++)
    {
      grid[i] = new int[width];
    }
    
    //writing 2D array
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        cin >> grid[i][j];
      }
    }
    
    //getting the most fish
    mostFish = 0;
    for (short j = 1; j < (width - 1); j++)
    {
      for (short i = 1; i < (height - 1); i++)
      {
        fishCaught = grid[i-1][j-1] +  grid[i-1][j] +  grid[i-1][j+1] +
                     grid[i][j-1] +  grid[i][j] +  grid[i][j+1] +
                     grid[i+1][j-1] +  grid[i+1][j] +  grid[i+1][j+1];
                                                  
        if (mostFish < fishCaught)
        {
          mostFish = fishCaught;
          bombWidth = j;
          bombHeight = i;
        }             
      }               
    }
    //de-allocating 2D array
    for (int i = 0; i < height; i++)
    {
      delete [] grid [i];
    }
    delete [] grid;
                        
    cout << "#" << k << ": (" << bombWidth << ", " 
         << bombHeight << ") " << mostFish << endl;
  }
  return 0;
}
