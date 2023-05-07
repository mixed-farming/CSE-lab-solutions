#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

__global__ void kernel(char* sin, char* sout)
{
    int id= threadIdx.x;
    int si = (id*(id+1))/2;
    for (int i = 0; i < id+1; i++)
    {
        sout[si++] = sin[id];
    }
}

int main()
{
    char *s="hai";
    int len = strlen(s);
    int out_len=(len*(len+1))/2;
    char *out = (char*) malloc(sizeof(char) * out_len);

    char* d_s;
    char* d_out; 

    cudaMalloc((void**) &d_s, len * sizeof(char));
    cudaMalloc((void**) &d_out, (out_len + 1) * sizeof(char));
    cudaMemcpy(d_s, s, len * sizeof(char), cudaMemcpyHostToDevice);

    kernel<<<1, strlen(s)>>>(d_s, d_out);
    cudaMemcpy(out, d_out, (out_len + 1) * sizeof(char), cudaMemcpyDeviceToHost);
    out[out_len] = '\0';

    printf("Sin: %s\n", s);
    printf("Sout: %s\n", out); 

    cudaFree(d_s);
    cudaFree(d_out);
    free(out);

    return 0;
}