#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void printsubarr(int sub[],int ls,int mainarr[],int lm){
	int l=lm-ls;
	int i,j,k=0,flag;

	for(i=0;i<lm;i++){
		flag = 1;
		for(j=0;j<ls;j++){
			if(mainarr[i] == sub[j]){
				flag = 0;
				break;
			}
		}
		if(flag == 1){

			printf("%d ",mainarr[i]);
		}
	}
	printf("}\n");
}

void solve(int arr[], int n){
	int totsum =0,i;
	for(i=0;i<n;i++){
		totsum+=arr[i];
	}
	if(totsum % 2 != 0){
		printf("\nCannot be divided into two subsets of equal sum.");
		return;
	}
	totsum/=2;
	int pow_set_size = pow(2,n);
	int counter, j,k;//generating subsets
	for(counter = 0; counter < pow_set_size; counter++)
	{
		int subarr[n];
		int c=0;
		for(j = 0; j < n; j++){
			if(counter & (1<<j))
				subarr[c++] = arr[j];
		}
		int sum =0;
		for(k=0;k<c;k++){
			sum+=subarr[k];
		}
		if(sum == totsum){
			printf("\nCan be divided into two subsets of equal sum.\n{");
			for(k=0;k<c;k++){
				printf("%d ",subarr[k]);
			}
			printf("} , { ");
			printsubarr(subarr,c,arr,n);
			return;
		}
	}
	printf("\nCannot be divided into two subsets of equal sum.");
	return;
}

int main(){
	int n,i;
	printf("\nEnter number of elements : ");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter elements : ");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	solve(arr,n);
	return 0;
}