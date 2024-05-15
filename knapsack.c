#include<stdio.h>

void swap(float *p,float *q)
{
  float temp = *p;
  *p = *q;
  *q = temp;
}

void swapBasedonPByW (float p[],float w[],int n)
{
  float PByW[n];
  int i,j,max=0;

  //calculating profit/weight ratio
  for(i=0;i<n;i++)
  {
    PByW[i] = p[i]/w[i];
  }

  //sorting according to highest P/W ratio
  for(i=0;i<n;i++)
  {
    max=i;
    for(j=i;j<n;j++)
    {
      if(PByW[max]<PByW[j])
        max=j;
    }

    swap(&p[i],&p[max]);
    swap(&w[i],&w[max]);
    swap(&PByW[i],&PByW[max]);
  }
}

void main()
{
  int i,n;
  float capactiy,profit=0.0;
  printf("\nEnter the capacity of knapsack: ");
  scanf("%f",&capactiy);
  printf("\nEnter number of items: ");
  scanf("%d",&n);
  float p[n],w[n],x[n];

  printf("\nEnter weight of Objects: ");
  for(i=0;i<n;i++)
  {
    scanf("%f",&w[i]);
    x[i]=0.0;
  }

  printf("\nEnter profit of Objects: ");
  for(i=0;i<n;i++)
  {
    scanf("%f",&p[i]);
  }

  swapBasedonPByW(p,w,n);

  for(i=0;i<n;i++)
  {
    if(w[i]>capactiy) break;
    x[i]=1.0;
    capactiy -= w[i];
    profit += p[i];
  }

  //if the loop breaks, then we use the fractional part
  if(i<n)
  {
    x[i] = capactiy/w[i];
    profit += x[i]*p[i];
  }

  printf("Profit: %f",profit);

}