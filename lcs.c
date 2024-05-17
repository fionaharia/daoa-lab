#include<stdio.h>
#include<string.h>

int LCS[100][100];
int i,j,n,m,n;
char x[100],y[100];
char direction[100][100]; //to store direction of choices

void calcLCS(char x[100],char y[100], int m,int n)
{
  for(i=0;i<=m;i++)
    LCS[i][0] = 0;
  for(j=0;j<=n;j++)
    LCS[0][j] = 0;
  for(i=1;i<=m;i++)
  {
    for(j=1;j<=n;j++)
    {
      if(x[i-1]==y[j-1])
        {
          LCS[i][j] = 1 + LCS[i-1][j-1];
          direction[i][j] = 'd';
        }
      else
      {
        if(LCS[i-1][j]>LCS[i][j-1]) //row>col
        {
          LCS[i][j] = LCS[i-1][j];
          direction[i][j] = 'u'; //up
        } 
        else
        {
          LCS[i][j] = LCS[i][j-1];
          direction[i][j] = 'l'; //left
        }
      }
    }
  }

  char lcs_seq[100];
  int index = LCS[m][n]; //length of lcs
  lcs_seq[index] = '\0';
  i = strlen(x);
  j = strlen(y);
  while(i>0 && j>0)
  {
    if(direction[i][j]=='d')
    {
      lcs_seq[--index] = x[i-1]; //backwards tracing
      i--;
      j--;
    }
    else if(direction[i][j]=='u')
      i--;
    else
      j--;
  }
  printf("LCS Sequence: %s\n",lcs_seq);
}


int main()
{
  printf("Enter the two strings: \n");
  scanf("%s",&x);
  scanf("%s",&y);
  m = strlen(x);
  n = strlen(y);
  calcLCS(x,y,m,n);  
  for(i=0;i<=m;i++)
  {
    for(j=0;j<=n;j++)
    {
      printf("%d ",LCS[i][j]);
    }
    printf("\n");
  }
  return 0;
}