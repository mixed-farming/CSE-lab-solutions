#include<stdio.h>
#include<math.h>
#include "cuda.h"

//matrix multiplication using 1d grid and 2d block

__global__ void matMul(int *a,int *b,int *c,int m,int n,int q)
{
    int row = threadIdx.y;
    int col = threadIdx.x;
    int sum = 0;
    int k;

    for (k = 0; k < n; k++) 
    {
        sum += a[row * n + k] * b[k * q + col];
    }
    c[row * q + col] = sum;
}

int main()
{
	int m=3, n=3, p=3, q=3, a[3][3]={{1,2,3},{4,5,6},{7,8,9}},b[3][3]={{0,1,2},{3,4,5},{6,7,8}}, c[3][3];
	printf("a:\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++) printf(" %d",a[i][j]);
		printf("\n");
	}
	printf("b:\n");
	for (int i=0;i<p;i++)
	{
		for (int j=0;j<q;j++) printf(" %d",b[i][j]);
		printf("\n");
	}

	int *d_a,*d_b,*d_mul; 
    size_t asize,bsize,cmsize;
	asize = m*n*sizeof(int); 
    bsize = p*q*sizeof(int);
    cmsize = m*q*sizeof(int);
	cudaMalloc((void**)&d_a,asize); 
    cudaMalloc((void**)&d_b,bsize);
    cudaMalloc((void**)&d_mul,cmsize);
	cudaMemcpy(d_a,a,asize,cudaMemcpyHostToDevice);
	cudaMemcpy(d_b,b,bsize,cudaMemcpyHostToDevice);
    dim3 block(n,m,1);
	matMul<<<1,block>>>(d_a,d_b,d_mul,m,n,q);
	cudaMemcpy(c,d_mul,cmsize,cudaMemcpyDeviceToHost);
	printf("\na*b:\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++) 
            printf(" %d",c[i][j]);
		printf("\n");
	}

	cudaFree(d_a); cudaFree(d_b);cudaFree(d_mul);
	return 0;
}
