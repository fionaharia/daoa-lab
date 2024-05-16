#include<stdio.h>
#include<string.h>

int main()
{
  char input[100];
  char pattern[100];
  printf("Enter text: ");
  scanf("%s",&input);
  printf("Enter pattern: ");
  scanf("%s",&pattern);

  int i=0,j=0,ptr=-1;
  while(i<strlen(input) && j<strlen(pattern))
  {
    if(input[i]==pattern[j]) //character match
    {
      if(j==0)
      {
        ptr = i; //update only when matched
      }
      i++;
      j++;
    }
    
    else ///character not match
    {
      if(ptr!=-1)
      {
        i = ptr + 1; //a match was previously found, so reset i 
      }
      else
      {
        i++; //move forward in the input string
      }
      j=0; //start from beginning in the pattern string
      ptr = -1; //reset ptr
    }
  }

  if(j==strlen(pattern))
    printf("Pattern found at index %d\n",ptr);
  else
    printf("Pattern not found");
  return 0;
}