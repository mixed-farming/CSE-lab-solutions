//Making an closed hash table

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int hash_tble[100];
int opcount = 0;
int make_hash(int arr[],int m,int n)
{
	for (int i =0;i<n;i++)
	{
		int h = arr[i]%m;
		if (hash_tble[h] != -1)
		{
			int j =0;
			while (i<m){
				h = (arr[i] + j*j)%m;
				if (hash_tble[h] != -1)
					j++;
				else
				{
					hash_tble[h] = arr[i];
					break;
				}
			}
		}
		else
			hash_tble[h] = arr[i];
		if (hash_tble[h] != arr[i])
		{
			printf("\nHash Table full");
			return -1;
		}
	}
	return 0;
}


void search_in_hash(int elm,int m)
{
	int h = (elm)%m;
	if (hash_tble[h] == elm){
		printf("\nElement Found!");
		return;
	}
	else
	{
		int j = 0;
		while (j<m){
			opcount++;
				h = (elm + j*j)%m;
				if (hash_tble[h] != elm)
					j++;
				else
				{
					printf("\nElement Found!");
					return;
				}
			}
		printf("\nElement not found in Hash Table");
		return;
	}
}
int main()
{
	int m = 10;
	int arr[] = {52,24,72,80,44,65,23,17};
	int n = 8;
	for (int i = 0;i<m;i++)
		hash_tble[i] = -1;
	int re = make_hash(arr,m,n);
	printf("\nThe Hash Table is ");
	for (int i=0;i<m;i++)
		printf("%d ",hash_tble[i]);
	search_in_hash(11,m);
	/*int a = n/m;
	int S=0.5(1+1/(1-a));
	int U=0.5(1+1/((1-a)*(1-a)));
	printf("Succe")*/
	printf("\nOperation Count: %d",opcount);
	return 0;

}