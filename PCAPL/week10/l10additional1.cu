#include <stdio.h>
#include <cuda.h>

__global__ void MatModify(int *a, int *c, int n, int m)
{
    int row = blockIdx.x;
    int col = threadIdx.x;
    int index = row * n + col;
    c[index] = 0;
    for(int i=0;i<n;i++)
    c[index]+=a[row*n+i];
    for(int i=0;i<m;i++)
    c[index]+=a[i*n+col];
}

int main()
{
    int n = 3, m = 2;
    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int c[2][3];
    int *d_a, *d_c;
   
    size_t asize = m * n * sizeof(int);
    cudaMalloc((void**)&d_a, asize);
    cudaMalloc((void**)&d_c, asize);
    cudaMemcpy(d_a, a, asize, cudaMemcpyHostToDevice);

    MatModify<<<m, n>>>(d_a, d_c, n, m);
    cudaMemcpy(c, d_c, asize, cudaMemcpyDeviceToHost);

    printf("Modified matrix:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    cudaFree(d_a);
    cudaFree(d_c);
    return 0;
}
