#include<stdio.h>

int main()
{
  int i,j;
  int d[10] = {1,4,6};
  int n=3;
  int N = 8;
  int dp[n+1][N+1];

  printf("Table: \n");
  for(i=0;i<=n;i++) //iterates through the coins
  {
    for(j=0;j<=N;j++) //iterated to obtain the total sum req
    {
      if(i==0 || j==0) //when no coins are used (first row in the table)
      {
        dp[i][j] = 0;
      }
      else if(i==1) //only one denomination is available
      {
        dp[i][j] = 1 + dp[i][j-d[i-1]]; 
      }
      else if(j<d[i-1]) //current denomination is greater than req current denomination
      {
        dp[i][j] = dp[i-1][j]; //inherits previous row value
      }
      else
      {
        if(dp[i-1][j]<1+dp[i][j-d[i-1]]) //takes the minimum value
        {
          dp[i][j] = dp[i-1][j];
        }
        else
        {
          dp[i][j] = 1+dp[i][j-d[i-1]];
        }
      }
    }
  }

  for (i = 0; i <= n; i++) //displaying table
  {
    for (j = 0; j <= N; j++) 
    {
      printf("%d ", dp[i][j]);
    }
    printf("\n");
  }

  i=n;
  j=N;
  printf("Coins used: \n");
  while(j>0 && i>0)
  {
    if(dp[i][j] == dp[i-1][j])
      i--; //inherited from prev row
    else
    {
      printf("%d ,",d[i-1]);
      j = j-d[i-1]; //subtracting the coin used from the sum
    }
  }
}