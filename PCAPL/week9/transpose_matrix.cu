#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>
__global__ void transpose(int *a, int *t)
{
int n=threadIdx.x, m=blockIdx.x, size=blockDim.x, size1=gridDim.x;
t[n*size1+m]=a[m*size+n];
}

int main(void)
{
  int a[2][3]={{1,2,3},{4,5,6}},t[3][2], m=2,n=3,i,j;
  int *d_a,*d_t;

  size_t size1=m*n*sizeof(int);
  cudaMalloc((void**)&d_a,size1);
  cudaMalloc((void**)&d_t,size1);
  cudaMemcpy(d_a,a,size1,cudaMemcpyHostToDevice);
  transpose<<<m,n>>>(d_a,d_t);
  cudaMemcpy(t,d_t,size1,cudaMemcpyDeviceToHost);
  printf("Result vector is:\n");
  for(i=0;i<n;i++)
  {
  for(j=0;j<m;j++)
  printf("%d\t",t[i][j]);
  printf("\n");
  }
  cudaFree(d_a);
  cudaFree(d_t);
  return 0;
}
