#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    int RQ[100],i,n,TotalHeadMoment=0,initial,count=0;
    printf("Enter the number of Requests\n");
    scanf("%d",&n);
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++)
     scanf("%d",&RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d",&initial);
    while(count!=n)
    {
        int min=INT_MAX,d,index;
        for(i=0;i<n;i++)
        {
           d=abs(RQ[i]-initial);
           if(d<min)
           {
               min=d;
               index=i;
           }
           
        }
        TotalHeadMoment=TotalHeadMoment+min;
        printf("%d ",TotalHeadMoment);
        initial=RQ[index];
        RQ[index]=INT_MAX;//forget the covered index
        count++;
    }
    printf("\nTotal head movement is %d",TotalHeadMoment);
    return 0;
}
