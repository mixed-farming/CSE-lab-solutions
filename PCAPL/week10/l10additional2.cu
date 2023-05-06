#include <stdio.h>
#include <cuda.h>

__global__ void MatModify(char *a, int *b, char *c, int n, int m)
{
    int row = blockIdx.x;
    int col = threadIdx.x;
    int index = row * n + col;
    int startindex=0;
    for(int i=0;i<index;i++)
    {
        startindex+=b[i];
    }
    for(int i=0;i<b[index];i++)
    {
        c[startindex++]=a[index];
    }
}

int main()
{
    int n = 4, m = 2;
    char a[2][4]={{'p','c','a','p'},{'e','x','a','m'}};
    int b[2][4] = {{1, 2, 4, 3}, {2, 4, 3, 2}};
    char *d_a, *d_c;
    int *d_b;
   
    size_t isize = m * n * sizeof(int);
    size_t csize = m * n * sizeof(char);
    int sum=0;
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    sum+=b[i][j];
    char c[sum];
    cudaMalloc((void**)&d_a, csize);
    cudaMalloc((void**)&d_b, isize);
    cudaMalloc((void**)&d_c, sum*sizeof(char));
    cudaMemcpy(d_a, a, csize, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, isize, cudaMemcpyHostToDevice);

    MatModify<<<m, n>>>(d_a, d_b, d_c, n, m);
    cudaMemcpy(c, d_c, sum*sizeof(char), cudaMemcpyDeviceToHost);
    printf("%s",c);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);
    return 0;
}
