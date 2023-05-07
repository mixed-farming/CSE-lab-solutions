#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

//minimum of row maximums

__global__ void row_max(int *a,int *rowmax)
{
    int idx=threadIdx.x+blockIdx.x*blockDim.x;
    atomicMax(&rowmax[blockIdx.x],a[idx]);
}

__global__ void minmax(int *rowmax,int *value)
{
    int idx=threadIdx.x;
    atomicMin(value,rowmax[idx]);
}

int main()
{
 int n=4;
 int a[4][4]={{5,6,7,4},{2,5,8,2},{9,7,4,1},{2,5,5,2}}, *d_a, *d_rowmax, rowmax[4];
 cudaMalloc((void**)&d_a, sizeof(int)*n*n);
 cudaMalloc((void**)&d_rowmax, sizeof(int)*n);
 cudaMemcpy(d_a,a,sizeof(int)*n*n,cudaMemcpyHostToDevice);
 
 row_max<<<n,n>>>(d_a,d_rowmax);

 cudaMemcpy(rowmax, d_rowmax, sizeof(int)*n, cudaMemcpyDeviceToHost);

  printf("Row maximums : ");
 for(int i=0;i<n;i++)
 {
     printf("%d ",rowmax[i]);
 }
  
  int x=1000,*d_value;
  cudaMalloc((void**)&d_value, sizeof(int));
  cudaMemcpy(d_value,&x,sizeof(int),cudaMemcpyHostToDevice);
  minmax<<<1,n>>>(d_rowmax,d_value);
  cudaMemcpy(&x,d_value,sizeof(int),cudaMemcpyDeviceToHost);
  printf("\nMinimum of row maximums : %d",x);

  cudaFree(d_a); cudaFree(d_rowmax);
  return 0;
}