#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int a[],int n,int *opcount)
{
	int flag;
	for (int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			flag=0;
			if(a[j]>a[j+1])
			{
				(*opcount)++;
				flag=1;
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		if(flag==0)
		{
			(*opcount)++;
		}
	}
}

int main(){
	int opcount,c,n,i,j;
	printf("\nEnter the number of test cases : ");
	scanf("%d",&c);
	for(i=0;i<c;i++){
		opcount=0;
		printf("Enter size of array : ");
		scanf("%d",&n);
		int a[n];
		printf("\nEnter the array elements : ");for(j=0;j<n;j++){
			scanf("%d",&a[j]);
		}
		BubbleSort(a,n,&opcount);//for ascending order sort
		printf("opcount = %d\tn = %d\t",opcount,n);
		printf("\nSorted Array : \n");
		for(j=0;j<n;j++){
			printf("%d ",a[j]);
		}
		printf("\n");
	}
}