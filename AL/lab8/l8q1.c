#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int opcount=0;

void heapify(int arr[], int currIndex)
{
    int parent = (currIndex)/2;
    opcount++;
    while(parent > 0)
    {
	    opcount++;
        if(arr[parent]<arr[currIndex])//swap parent n child values in array
        {
            int temp = arr[parent];
            arr[parent] = arr[currIndex];
            arr[currIndex] = temp;

            currIndex = parent;//swap their indices.
            parent = (currIndex)/2;
        }
        else
            return;
    }
}


int main(){
    int n;
    printf("\nEnter number of elements : ");
    scanf("%d",&n);
    int *h = (int*)malloc((sizeof(int))*(n));
    printf("\nEnter elements : ");
    for(int i=1;i<=n;i++){//array implementation starts from 1 for heaps
        scanf("%d",&h[i]);
        heapify(h,i);
    }
    printf("\nThe heap created is : ");//display heap
    for(int i=1;i<=n;i++){
        printf("%d ",h[i]);
    }
    printf("\n");
    printf("\nThe Opcount is : %d",opcount);
    return 0;
}