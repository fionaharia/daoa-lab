#include<stdbool.h>
#include<stdio.h>
#define MAX_SIZE 50

int set[MAX_SIZE];
bool choosen[MAX_SIZE];
int sum,n,i,j;

void printSubset(int n)
{
  printf("{ ");
  for(i=0;i<n;i++)
  {
    if(choosen[i])
    {
      printf("%d ,",set[i]);
    }
  }
  printf("}");
}

void subsets(int current_index,int current_sum) //recusrive function
{
  if(current_index==n) //all numbers in subsets are considered
  {
    if(current_sum==sum)
    {
        printSubset(n);
    }
    return;
  }
  //include and call recursively
  choosen[current_index] = true;
  subsets(current_index+1,current_sum+set[current_index]);

  //exclude and call recursively
  choosen[current_index] = false;
  subsets(current_index+1,current_sum);
}

int main()
{
  printf("Enter the number of elements: \n");
  scanf("%d",&n);
  printf("Enter %d elements: \n",n);
  for(i=0;i<n;i++)
    scanf("%d",&set[i]);
  printf("Enter the total sum required: \n");
  scanf("%d",&sum);
  printf("Subsets with sum equal to %d are \n",sum);
  subsets(0,0);
  return 0;
}