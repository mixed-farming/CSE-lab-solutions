//Given an NXN matrix mat, where N is an even number and N >= 4, 
//write a CUDA program to find major diagonal sums of partial matrices in the four different quadrants 
//(vertical and horizontal lines are drawn to partition the matrix into 4 quadrants) of mat in parallel as shown below in sample Input/Output. 
//Use 2X2 grid with 1 thread per block. The first parameter to the kernel is the matrix and the second is an 1D array of size 4 to store 4 different diagonal sums 
//computed by 4 different threads of 4 different blocks. Pass any other parameters if necessary. Read N and mat contents in the host code.  
//Display the matrix mat and the diagonal sums in the host code. The code should work for any value of N satisfying the condition mentioned above. 
//Use dynamic allocation for all the host arrays.
/*
i/p:
0 1 2  3 4 5            
1 2 3  4 5 6            
2 3 4  5 6 7            
3 4 5  6 7 8            
4 5 6  7 8 9            
5 6 7  8 9 10
o/p:
Diagonal sums from threads of different blocks:
From block 0 diagonal Sum = 6  
From block 1 diagonal Sum = 15
From block 2 diagonal Sum = 15 
From block 3 diagonal Sum = 24
*/

#include <stdio.h>
#include <cuda.h>

__global__ void diagonalSumKernel(int* mat, int* diagSums, int n) {
    int bid_x = blockIdx.x;
    int bid_y = blockIdx.y;
    int rowStart = bid_x * n/2;
    int colStart = bid_y * n/2;
    int sum = 0;
    for (int i = 0; i < n/2 ; i++) {
        sum += mat[(rowStart + i) * n + colStart + i];
    }
    diagSums[bid_x * 2 + bid_y] = sum;
}

int main() {
    int n=6, *diagSums;
    int size = n * n * sizeof(int);
    int size_ds = 4 * sizeof(int);

    // Allocate memory for matrix and diagonal sums array on host
    diagSums = (int*)malloc(size_ds);
    int mat[6][6]={{0,1,2,3,4,5},{1,2,3,4,5,6},{2,3,4,5,6,7},{3,4,5,6,7,8},{4,5,6,7,8,9},{5,6,7,8,9,10}};

    int *d_mat, *d_diagSums;
    cudaMalloc((void**)&d_mat, size);
    cudaMalloc((void**)&d_diagSums, size_ds);
    cudaMemcpy(d_mat, mat, size, cudaMemcpyHostToDevice);
    dim3 grid(2, 2, 1);
    diagonalSumKernel<<<grid, 1>>>(d_mat, d_diagSums, n);

    cudaMemcpy(diagSums, d_diagSums, size_ds, cudaMemcpyDeviceToHost);

    printf("\nDiagonal sums from threads of different blocks:\n");
    for (int i = 0; i < 4; i++) {
        printf("From block %d diagonal Sum = %d\n", i, diagSums[i]);
    }

    free(diagSums);
    cudaFree(d_mat);
    cudaFree(d_diagSums);

    return 0;
}
