%%cu
#include<stdio.h>
#include<math.h>
#include "cuda.h"
__global__ void matRowAdd(int *a,int *b,int *c,int m,int n)
{
	int row=threadIdx.x;
	for (int i=0;i<n;i++) c[row*n+i]=a[row*n+i]+b[row*n+i];
}
__global__ void matColAdd(int *a,int *b,int *c,int m,int n)
{
	int col=threadIdx.x;
	for (int i=0;i<m;i++) c[i*n+col]=a[i*n+col]+b[i*n+col];
}
__global__ void matAdd(int *a,int *b,int *c,int m,int n)
{
	int row=blockIdx.y*blockDim.y + threadIdx.y;
	int col=blockIdx.x*blockDim.x + threadIdx.x;
	if (row<m && col<n) c[row*n+col]=a[row*n+col]+b[row*n+col];
}
__global__ void matRowMul(int *a,int *b,int *c,int n,int q)
{
	int rowidA=threadIdx.x,sum,k;
	for (int colidB=0;colidB<q;colidB++)
	{
		sum=0;
		for (k=0;k<n;k++) sum=sum+a[rowidA*n+k]*b[k*q+colidB];
		c[rowidA*q+colidB]=sum;
	}
}
__global__ void matColMul(int *a,int *b,int *c,int m,int n)
{
	int colidB=threadIdx.x,q=blockDim.x,sum,k;
	for (int rowidA=0;rowidA<m;rowidA++)
	{
		sum=0;
		for (k=0;k<n;k++) sum=sum+a[rowidA*n+k]*b[k*q+colidB];
		c[rowidA*q+colidB]=sum;
	}
}
__global__ void matMul(int *a,int *b,int *c,int m,int n,int q)
{
	int row=threadIdx.y;
	int col=threadIdx.x;
	int sum=0,k;
	if (row<m && col<q) for (k=0;k<n;k++) sum=sum+a[row*n+k]*b[k*q+col];
	c[row*q+col]=sum;
}
int main()
{
	int m=3, n=3, p=3, q=3, blocksize=2, a[3][3]={{1,2,3},{4,5,6},{7,8,9}},
	b[3][3]={{0,1,2},{3,4,5},{6,7,8}}, c[3][3];
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

	int *d_a,*d_b,*d_add,*d_mul; size_t asize,bsize,casize,cmsize;
	asize = m*n*sizeof(int); bsize = p*q*sizeof(int);
	casize = m*n*sizeof(int); cmsize = m*q*sizeof(int);
	cudaMalloc((void**)&d_a,asize); cudaMalloc((void**)&d_b,bsize);
	cudaMalloc((void**)&d_add,casize); cudaMalloc((void**)&d_mul,cmsize);
	cudaMemcpy(d_a,a,asize,cudaMemcpyHostToDevice);
	cudaMemcpy(d_b,b,bsize,cudaMemcpyHostToDevice);
	dim3 block(2,2,1);

	matRowAdd<<<1,m>>>(d_a,d_b,d_add,m,n);
	cudaMemcpy(c,d_add,casize,cudaMemcpyDeviceToHost);
	printf("1.(a) a+b:\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++) printf(" %d",c[i][j]);
		printf("\n");
	}

	matColAdd<<<1,n>>>(d_a,d_b,d_add,m,n);
	cudaMemcpy(c,d_add,casize,cudaMemcpyDeviceToHost);
	printf("1.(b) a+b:\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++) printf(" %d",c[i][j]);
		printf("\n");
	}

	dim3 grid(ceil(m/(float)blocksize),ceil(n/(float)blocksize),1);
	matAdd<<<grid,block>>>(d_a,d_b,d_add,m,n);
	cudaMemcpy(c,d_add,casize,cudaMemcpyDeviceToHost);
	printf("1.(c) a+b:\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++) printf(" %d",c[i][j]);
		printf("\n");
	}

	matRowMul<<<1,m>>>(d_a,d_b,d_mul,n,q);
	cudaMemcpy(c,d_mul,cmsize,cudaMemcpyDeviceToHost);
	printf("2.(a) a*b:\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++) printf(" %d",c[i][j]);
		printf("\n");
	}

	matColMul<<<1,q>>>(d_a,d_b,d_mul,m,n);
	cudaMemcpy(c,d_mul,cmsize,cudaMemcpyDeviceToHost);
	printf("2.(b) a*b:\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++) printf(" %d",c[i][j]);
		printf("\n");
	}

	dim3 mulgrid(ceil((q+blocksize-1)/blocksize),ceil((m+blocksize-1)/blocksize),1);
	matMul<<<mulgrid,block>>>(d_a,d_b,d_mul,m,n,q);
	cudaMemcpy(c,d_mul,cmsize,cudaMemcpyDeviceToHost);
	printf("2.(c) a*b:\n");
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++) printf(" %d",c[i][j]);
		printf("\n");
	}

	cudaFree(d_a); cudaFree(d_b); cudaFree(d_add); cudaFree(d_mul);
	return 0;
}