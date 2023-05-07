#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

//selection sort

__global__ void sort(int *a, int *b,int m, int n)
{

 int row = blockIdx.y * blockDim.y + threadIdx.y;
    int start = row * n;
    int end = start + n;

    for (int i = start; i < end - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < end; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        // Swap elements
        int tmp = a[i];
        a[i] = a[min_idx];
        a[min_idx] = tmp;
    }

    // Copy sorted row to output matrix
    for (int i = start; i < end; i++) {
        b[i] = a[i];
    }
}

int main()
{
 int m=3,n=4;
 int a[m][n]={{4,2,3,1},{6,5,4,3},{8,6,7,5}},b[m][n];
 int *d_a,*d_b;
 cudaMalloc((void**)&d_a,sizeof(int)*m*n);
 cudaMalloc((void**)&d_b,sizeof(int)*m*n);
 cudaMemcpy(d_a,a,sizeof(int)*m*n,cudaMemcpyHostToDevice);
 int s=2;
 dim3 block(s,s,1);
 dim3 grid((n+s-1)/s,(m+s-1)/s,1);
 sort<<<grid,block>>>(d_a,d_b,m,n);
 cudaMemcpy(b,d_b,sizeof(int)*m*n,cudaMemcpyDeviceToHost);
 for(int i=0;i<m;i++)
 {
     for(int j=0;j<n;j++)
     {
         printf("%d ",b[i][j]);
     }
  printf("\n");
 }

 cudaFree(d_a); cudaFree(d_b);
 return 0;
}

