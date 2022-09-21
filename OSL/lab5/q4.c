#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr;
    fptr=fopen("test.bin","wb+");
    fputs("Sample check",fptr);
    fclose(fptr);
    fptr=fopen("test.bin","rb");
    char buf[100];
    fgets(buf,sizeof(buf),fptr);
    printf("File contents : %s\n",buf);
    return 0;
}