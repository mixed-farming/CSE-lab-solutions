#include <stdio.h>
#include <stdlib.h>

int opcount=0;

void Merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1 = m - l + 1;//size of left array...+1 bcuz even 'l'th element is also included
	int n2 = r - m;//size of right array

	int L[n1],R[n2];//array for left and right sections

	//copying the contents from array to subarrays...
	for(int i=0;i<n1;i++)
	{
		L[i] = arr[l+i];
	}
	for(int j=0;j<n2;j++)
	{
		R[j] = arr[m+1+j];
	}

	//merging subarrays to get back arr
	i=0;//initial index of first subarray
	j=0;//initial index of second subarray
	k=l;//initial index of merged subarray

	while (i < n1 && j < n2)
	{
		opcount++;
		if(L[i] <= R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}

	//copying the remaining elements from L[] or R[] to arr if any
	while(i<n1)
	{
		opcount++;
		arr[k]=L[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		opcount++;
		arr[k]=R[j];
		j++;
		k++;
	}
}

void MergeSort(int arr [],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		MergeSort(arr,l,m);//divide left half of the array until its further indivisible
		MergeSort(arr,m+1,r);//divide right half of the array until its further indivisible

		Merge(arr,l,m,r);//merge the individual halves
	}
}

int main()
{
	int n;
	printf("Enter the number of numbers in the array : ");
	scanf("%d",&n);
	int arr[n];
	printf("Populate the array : ");
	for (int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	MergeSort(arr,0,n-1);
	printf("Sorted array : ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}

	printf("The Opcount is : %d",opcount);
	printf("\n");
	return 0;
}
