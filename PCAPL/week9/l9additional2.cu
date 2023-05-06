#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>
__global__ void modify(int *a, int *t, int n)
{
  int row=blockIdx.x, col=threadIdx.x;
  int index=row*n+col;
  if(row==col)
  t[index]=0;
 else if(row<col)
 {
     t[index]=1;
      for(int i=a[index];i>1;i--)
      {
          t[index]*=i;
      }
 }
 else
 {
     t[index]=0;
      while(a[index])
      {
          t[index]+=(a[index]%10);
          a[index]/=10;
      }
 }
}

int main(void)
{
  int a[3][3]={{4,5,6},{49,50,7},{79,84,91}},t[3][3], n=3,i,j;
  int *d_a,*d_t;

  size_t size1=n*n*sizeof(int);
  cudaMalloc((void**)&d_a,size1);
  cudaMalloc((void**)&d_t,size1);
  cudaMemcpy(d_a,a,size1,cudaMemcpyHostToDevice);
  dim3 grid(n,1,1);
  dim3 block(n,1,1);
  modify<<<grid, block>>>(d_a, d_t, n);
  cudaMemcpy(t,d_t,size1,cudaMemcpyDeviceToHost);
  printf("Modified matrix is:\n");
  for(i=0;i<n;i++)
  {
  for(j=0;j<n;j++)
  printf("%d\t",t[i][j]);
  printf("\n");
  }
  cudaFree(d_a);
  cudaFree(d_t);
  return 0;
}
