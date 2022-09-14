#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  int countline=0,countc=0;
  FILE *fptr;
  fptr=fopen("temp.txt","r");
  if(!fptr)
  {
    printf("Cannot open the file\n");
    exit(1);
  }

  char c;
  c=getc(fptr);
  while(c!=EOF)
  {
    if(c=='\n')
    {
      countline++;
    }
    else
    {
      countc++;
    }

    c=getc(fptr);
  }  

  printf("Total number of lines = %d\nTotal number of characters = %d\n",countline,countc);
  fclose(fptr);

  return 0;
}
