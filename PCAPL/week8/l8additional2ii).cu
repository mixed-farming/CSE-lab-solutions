#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//number of threads = length of the string

__global__ void kernel(char* sin, int n, char* sout)
{
    int si = threadIdx.x,len=blockDim.x; 
    for (int i = 0; i < n; i++)
    {
        sout[si+i*len] = sin[si];
    }
}

int main()
{
    char *s="hello";
    int n=3;
    char *out = (char*) malloc((strlen(s) + 1) * sizeof(char) * n);

    int len = strlen(s);
    int out_len=len*n;

    char* d_s;
    char* d_out; 

    cudaMalloc((void**) &d_s, len * sizeof(char));
    cudaMalloc((void**) &d_out, (out_len + 1) * sizeof(char));
    cudaMemcpy(d_s, s, len * sizeof(char), cudaMemcpyHostToDevice);

    kernel<<<1, strlen(s)>>>(d_s, n, d_out);
    cudaMemcpy(out, d_out, (out_len + 1) * sizeof(char), cudaMemcpyDeviceToHost);
    out[out_len] = '\0';

    printf("Sin: %s\n", s);
    printf("Sout: %s\n", out); 

    cudaFree(d_s);
    cudaFree(d_out);
    free(out);

    return 0;
}