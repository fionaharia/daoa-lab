#include<stdio.h>
#include<limits.h>

void swap(int *p,int *q)
{
  int temp = *p;
  *p = *q;
  *q = temp;
}

void sortBasedonProfits(int n,int jobs[],int deadlines[],int profits[])
{
  int i,j;
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(profits[i]<profits[j])
      {
          swap(&jobs[i],&jobs[j]);
          swap(&deadlines[i],&deadlines[j]);
          swap(&profits[i],&profits[j]);
      }
    }
  }
}

void scheduleJobs(int n,int jobs[],int deadlines[],int profits[])
{
  int i,j,maxdeadline = deadlines[0], maxProfit = 0;
  
  //finding the max deadline
  for(i=1;i<n;i++)
  {
    if(maxdeadline < deadlines[i])
      maxdeadline = deadlines[i];
  }

  int jobsaccepted[maxdeadline];

  //initalising all jobs to -1
  for(i=0;i<maxdeadline;i++)
  {
    jobsaccepted[i] = -1;
  }

  for(i=0;i<n;i++)
  {
    // this loop is to check the jobsaccepted array
    for(j=deadlines[i]-1;j>=0;j--)
    {
      if(jobsaccepted[i]==-1)
      {
        jobsaccepted[j] = jobs[i];
        maxProfit += profits[i];
        break;
      }
    }
  }

  printf("Jobs accepted in the order are: \n");
  for(i=0;i<maxdeadline;i++)
  {
    printf("%d \n",jobsaccepted[i]);
  }
  printf("Maximum Profit: %d\n",maxProfit);
}

int main()
{
  int i, n;
  printf("Enter no. of Jobs: ");
     scanf("%d", &n);
     int jobs[n], deadlines[n], profits[n];
     for(i = 0 ; i < n ; i++) jobs[i] = i+1;
     printf("Enter Deadlines: ");
     for(i = 0 ; i < n ; i++) scanf("%d", &deadlines[i]);
     printf("Enter Profits: ");
     for(i = 0 ; i < n ; i++) scanf("%d", &profits[i]);
     sortBasedonProfits(n, jobs, deadlines, profits);
     for(i = 0 ; i < n ; i++){
          printf("%d %d %d\n", jobs[i], profits[i], deadlines[i]);
     }
     scheduleJobs(n, jobs, deadlines, profits);
}


