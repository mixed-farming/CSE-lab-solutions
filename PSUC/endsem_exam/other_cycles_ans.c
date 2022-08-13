#include <stdio.h>
#include <stdlib.h>

void generateARow(int R, int NR, char rowstr[])
{
    int k,l=0;
    char num[10][2]= {"On","Tw","Th","Fo","Fi","Si","Se","Ei","Ni","Te"};
    for(k=0; k<=NR-R; k++)
        for(; l<5*k; l++)
            rowstr[l]=' ';
    for(k=0; k<R; k++)
    {
        rowstr[l]=num[k][0];
        rowstr[++l]=num[k][1];
        rowstr[++l]=' ';
        rowstr[++l]=' ';
        rowstr[++l]=' ';
        rowstr[++l]=' ';
    }
    for(k=R-2; k>-1; k--)
    {
        rowstr[l]=num[k][0];
        rowstr[++l]=num[k][1];
        rowstr[++l]=' ';
        rowstr[++l]=' ';
        rowstr[++l]=' ';
        rowstr[++l]=' ';
    }
    for(k=0; k<l; k++)
        printf("%c",rowstr[k]);
    printf("\n");
}
int main()
{
    char rowstr[100];
    int i,j,N;
    printf("Name : MANOJ M MALLYA\nReg number : 200905130");
    int NR;
    printf("\n\nEnter number of rows in the pyramid: ");
    scanf("%d",&NR);
    for(i=1; i<=NR; i++)
        generateARow(i,NR,rowstr);
    printf("\nEnter a number: ");
    scanf("%d",&N);
    if(N==0)
        for(i=1; i<=NR; i++)
            generateARow(i,NR,rowstr);
    else if(N<=NR)
        generateARow(N,NR,rowstr);
    else
    {
        for(i=1; i<=NR; i++)
            generateARow(i,NR,rowstr);
        for(i=NR-1; i>0; i--)
            generateARow(i,NR,rowstr);
    }
    return 0;
}
