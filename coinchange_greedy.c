#include<stdio.h>
#include<stdlib.h>

void coinSort(int den[],int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-1-1-i;j++)
    {
      if(den[j]<den[j+1])
      {
        temp = den[j];
        den[j] = den[j+1];
        den[j+1] = temp;
      }
    }
  }
}

int main()
{
  int i,n,quotient,amt,temp,cnt=0,*den;
  printf("Enter the number of denominations: \n");
  scanf("%d",&n);
  den = (int *)malloc(n*sizeof(int));

  printf("Enter the denominations: \n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&den[i]);
  }

  printf("Enter the amount: \n");
  scanf("%d",&amt);
  coinSort(den,n);
  temp = amt;

  for(i=0;i<n;i++)
  {
    //number of times the denomination can be subtracted from the remaining amount
    quotient = (int)(amt/den[i]);

    //subtracting the number of times the denomiation can be subtracted
    amt -= quotient*den[i];

    //count of coins
    cnt += quotient;
    if(quotient!=0)
      printf("%-4d: %d\n",den[i],quotient);
    if(amt==0)
      break;
  }

  printf("Minimum number of denominations: %d\n",cnt);
  printf("Obtained amount: %d\n",temp-amt);
  printf("Remaining Amount: %d\n",amt);
  return 0;
}