#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>

__global__ void modify(int *y, int *x, int alpha, int n)
{
    int tid = threadIdx.x;
    if(tid<n)
    {
        y[tid] = alpha * x[tid] + y[tid];
    }
}

int main()
{
    int n=10;
    int y[10]={1,3,9,4,5,2,7,8,6,0},x[10]={0,2,4,6,8,1,3,5,7,9}, *d_y, *d_x;
    int alpha=6;

    cudaMalloc(&d_y, n * sizeof(int));
    cudaMemcpy(d_y, y, n * sizeof(int), cudaMemcpyHostToDevice);
    cudaMalloc(&d_x, n * sizeof(int));
    cudaMemcpy(d_x, x, n * sizeof(int), cudaMemcpyHostToDevice);

    modify<<<1, 256>>>(d_y, d_x, alpha, n);

    int z[10];
    cudaMemcpy(z, d_y, n * sizeof(int), cudaMemcpyDeviceToHost);

    printf("Modified vector : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",z[i]);
    }

    cudaFree(d_y);
    cudaFree(d_x);

    return 0;
}
