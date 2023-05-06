#include <stdio.h>
#include <cuda.h>
#include <cuda_runtime.h>

__global__ void kkernel(int *A, int m, int n)
{
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int sum = 0, digit, power = 1;
    char binnum[10];
    int num, rem, k = 0;
    if ((row > 0 && row < n - 1) && (col > 0 && col < m - 1))
    {
        num = A[row * n + col];
        while (num > 0)
        {
            rem = num % 2;
            if (rem == 1)
                binnum[k++] = '1';
            else
                binnum[k++] = '0';
            num /= 2;
        }
        k--;
        int t;
        printf("before reverse %s\n", binnum);
        for (int i = 0; i <= k / 2; i++)
        {
            t = binnum[i];
            binnum[i] = binnum[k - i];
           binnum[k - i] = t;
        }
        printf("row no %d and col no. %d after reverse %s\n", row, col, binnum);
        for (int i = k; i >= 0; i--)
        {
            if (binnum[i] == '1')
                digit = 0;
            else
                digit = 1;
            sum += digit * power;
            power = power * 10;
        }
        A[row * n + col] = sum;
    }
}
int main()
{
    int A[4][4] = {{1, 2, 3, 4}, {6, 5, 8, 3}, {2, 4, 10, 1}, {9, 1, 2, 5}};
    int i, j;
    int M = 4, N = 4;
    int vsize = (M * N) * sizeof(int);
    int B[vsize];
    int k = 0;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
           B[k++] = A[i][j];
    }
    int *d_A;
    cudaMalloc((void **)&d_A, sizeof(int) * (vsize));
    cudaMemcpy(d_A, B, sizeof(int) * (vsize), cudaMemcpyHostToDevice);
    float BSIZE = 2;
    dim3 blck(BSIZE, BSIZE, 1);
    dim3 grid(ceil(N / BSIZE), ceil(M / BSIZE), 1);
    kkernel<<<grid, blck>>>(d_A, M, N);
    cudaMemcpy(B, d_A, vsize, cudaMemcpyDeviceToHost);
    k = 0;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
            A[i][j] = B[k++];
    }
    printf("\n");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    return 0;
}
