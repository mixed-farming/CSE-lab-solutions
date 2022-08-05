//Quick Sort
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int opcount =0;


void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int A[],int left,int right)
{
	int pivot = A[right];
	int i = (left - 1);

	for (int j = left; j < right; j++) {
		opcount++;
		if (A[j] <= pivot) {
			i++;
			opcount++;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i + 1], &A[right]);
	return (i + 1);


}
void quick_sort(int A[],int left,int right)
{
	opcount++;
	if (left<right)
	{
		int pivot_index = partition(A,left,right);
		quick_sort(A,left,pivot_index-1);
		quick_sort(A,pivot_index,right);
	}
}


int main()
{
	int A[] = {5,11,0,9,2,12,3};
	int n = 7;
	quick_sort(A,0,n);
	printf("\nThe Sorted Array is:\n");
	for (int i = 0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\nOperation Count: %d",opcount);
	return 0;
}