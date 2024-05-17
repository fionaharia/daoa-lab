#include<stdio.h>

int tspCalc(int n,int dist[n][n],int visited, int current)
{
  if(visited==(1<<n)-1)
    return dist[current][0]; //current city back to starting city
  int min=1000;
  for(int i=0;i<n;i++)
  {
    if(!(visited & (1<<i)))
    {
      int new_cost = dist[current][i] + tspCalc(n,dist,visited | (1<<i),i);
      if(new_cost<min)
        min = new_cost;
    }
  }
  return min;
}


int main()
{
  int n=4;
  int dist[4][4] = {{0, 10, 15, 20}, 
                    {5, 0, 9, 10}, 
                    {6, 13, 0, 12}, 
                    {8, 8, 9, 0}};
  int cost = tspCalc(n,dist,1,0);
  printf("Minimum Cost: %d",cost);
  return 0;
}