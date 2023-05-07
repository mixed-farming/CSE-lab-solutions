#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <string.h>

__global__ void function(char* a, int* b, int len)
{
    int idx = threadIdx.x;
    int start = b[idx] + 1;
    int end = b[idx + 1];
    
    for (int i = start, j = end-1; i < j; i++, j--) {
        char temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main()
{
    char *a = "i erocs lluf ni lpacp mesdne";
    char *c = (char*) malloc((strlen(a) + 1) * sizeof(char));
    int len = strlen(a);
    size_t s = len * sizeof(char);

    int b[10];
    int k = 0;
    b[k++] = -1;
    
    for (int i = 0; i < len; i++) {
        if (a[i] == ' ') {
            b[k++] = i;
        }
    }
    b[k++] = len;
    
    char *d_a;
    int *d_b;
    int words=k+1;//words=number of spaces+1
    
    cudaMalloc((void**)&d_a, s);
    cudaMalloc((void**)&d_b, words * sizeof(int));
    
    cudaMemcpy(d_a, a, s, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, b, words * sizeof(int), cudaMemcpyHostToDevice);
    
    function<<<1, words>>>(d_a, d_b, len);
    
    cudaMemcpy(c, d_a, s, cudaMemcpyDeviceToHost);
    printf("%s\n", c);
    
    cudaFree(d_a);
    cudaFree(d_b);
    free(c);
 
    return 0;
}
