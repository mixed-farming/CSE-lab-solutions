#include <stdio.h>
#include <cuda.h>

//odd-even transposition sort

__global__ void oddSort(int* array, int n)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i % 2 == 1 && i < n - 1) {
        if (array[i] > array[i+1]) {
            int tmp = array[i];
            array[i] = array[i+1];
            array[i+1] = tmp;
        }
    }
}

__global__ void evenSort(int* array, int n)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i % 2 == 0 && i < n - 1) {
        if (array[i] > array[i+1]) {
            int tmp = array[i];
            array[i] = array[i+1];
            array[i+1] = tmp;
        }
    }
}

int main()
{
    const int n = 10;
    int h_array[n] = {7, 2, 9, 4, 6, 1, 3, 8, 5, 0};
    int* d_array;

    cudaMalloc(&d_array, n * sizeof(int));
    cudaMemcpy(d_array, h_array, n * sizeof(int), cudaMemcpyHostToDevice);

    dim3 block(32);
    dim3 grid((n + block.x - 1) / block.x);

    // Odd-even transposition sort loop
    for (int i = 0; i < n; i++) {
        oddSort<<<grid, block>>>(d_array, n);
        evenSort<<<grid, block>>>(d_array, n);
    }

    cudaMemcpy(h_array, d_array, n * sizeof(int), cudaMemcpyDeviceToHost);

    for (int i = 0; i < n; i++) {
        printf("%d ", h_array[i]);
    }
    printf("\n");

    cudaFree(d_array);

    return 0;
}
