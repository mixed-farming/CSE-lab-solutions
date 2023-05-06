#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>
__global__ void modify(int *a, int *t, int n,int m)
{
    int row=blockIdx.x, col=threadIdx.x;
    int index=row*n+col;
 int sum=0;
    if(a[index]%2==0)
    {
        for(int i=0;i<n;i++)
        {
            sum+=a[row*n+i];
        }
     t[index]=sum;
    }
    else
 {
   for(int i=0;i<m;i++)
   {
       sum+=a[i*n+col];
   }
  t[index]=sum;
 }

}

int main(void)
{
  int a[2][3]={{1,2,3},{4,5,6}},t[2][3], m=2,n=3,i,j;
  int *d_a,*d_t;

  size_t size1=m*n*sizeof(int);
  cudaMalloc((void**)&d_a,size1);
  cudaMalloc((void**)&d_t,size1);
  cudaMemcpy(d_a,a,size1,cudaMemcpyHostToDevice);
  modify<<<m,n>>>(d_a,d_t,n,m);
  cudaMemcpy(t,d_t,size1,cudaMemcpyDeviceToHost);
  printf("Result vector is:\n");
  for(i=0;i<m;i++)
  {
  for(j=0;j<n;j++)
  printf("%d\t",t[i][j]);
  printf("\n");
  }
  cudaFree(d_a);
  cudaFree(d_t);
  return 0;
}
