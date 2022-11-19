#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numSecteur=10;
    char sectuer[1024];
    FILE *disqueF=fopen("media/student","r");
    fseek(disqueF,numSecteur*512,SEEK_SET);
    fread(sectuer,1024,1,disqueF);
    for(int i=0;i<sizeof(sectuer);i++)
    {
        printf("%x",sectuer[i]);
        if((i+1)%16==0)
        printf("\n");
    }
    fclose(disqueF);
    return 0;
}