#include<stdio.h>
#include<stdbool.h>
#define V 6
#define MAX 1000

int main()
{
  int i,j;
  int graph[V][V] = {
      {0, 7, 9, 0, 0, 14},
      {7, 0, 10, 15, 0, 0},
      {9, 10, 0, 11, 0, 2},
      {0, 15, 11, 0, 6, 0},
      {0, 0, 0, 6, 0, 9},
      {14, 0, 2, 0, 9, 0}
  };

  int dist[V]; //shortest distances from the source to each vertex
  bool visited[V]; //which vertices have been included in the shortest path tree

  for(i=0;i<V;i++)
  {
    dist[i] = MAX;
    visited[i] = false;
  }

  int src = 0;
  dist[src] = 0;

  for(i=0;i<V-1;i++)
  {
    int u=-1;
    
    for(j=0;j<V;j++) //finding the minimum distance to vertex u
      if(!visited[j] && (u==-1 || dist[j] < dist[u]))
        u=j; //updating the minimum dist to u
    
    visited[u] = true;

    //once we select the u vertex, we will find the vertex connected to u vertex
    for(int v=0;v<V;v++)
    {
      //not visited, egde should exist between u and v
      //if its still MAX, it means it has no direct edge and hasnt reached yet
      if(!visited[v] && graph[u][v] && dist[u] != MAX)
      {
        if(dist[u] + graph[u][v] < dist[v])
          dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  printf("Vertex Distance from the source: \n");
  for(i=0;i<V;i++)
    printf("%d \t\t %d \n",i,dist[i]);
  return 0;
}