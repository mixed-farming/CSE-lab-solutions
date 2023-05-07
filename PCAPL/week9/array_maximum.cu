#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>

//array maximum

__global__ void find_max(int *arr, int *max_val)
{
    int tid = threadIdx.x;
    atomicMax(max_val, arr[tid]);
}

int main()
{
    int n=10;
    int arr[10]={10,30,90,40,50,20,70,80,60,37}, *d_arr, *d_max;
    int max_val = 0;

    cudaMalloc(&d_arr, n * sizeof(int));
    cudaMalloc(&d_max, sizeof(int));

    cudaMemcpy(d_arr, arr, n * sizeof(int), cudaMemcpyHostToDevice);

    find_max<<<1, 256>>>(d_arr, d_max);

    cudaMemcpy(&max_val, d_max, sizeof(int), cudaMemcpyDeviceToHost);

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n\nMax value: %d\n", max_val);

    cudaFree(d_arr);
    cudaFree(d_max);

    return 0;
}
