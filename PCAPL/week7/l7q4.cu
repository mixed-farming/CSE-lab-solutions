#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cuda_runtime.h>
 
__global__ void compute_sine(float* input, float* output, int size) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < size) {
        output[i] = sinf(input[i]);
    }
}
 
int main() {
    int size = 180;//divides the interval 0-2pi into 180 parts each spaced by 1/180
    size_t bytes = size * sizeof(float);
 
    float* input = (float*)malloc(bytes);
    for (int i = 0; i < size; i++) {
        input[i] = (float)i / size * 2 * 3.14159;
    }
 
    float* output = (float*)malloc(bytes);
    float* d_input;
    float* d_output;
    cudaMalloc((void**)&d_input, bytes);
    cudaMalloc((void**)&d_output, bytes);
    cudaMemcpy(d_input, input, bytes, cudaMemcpyHostToDevice);
 
    int block_size = 256;
    int num_blocks = (size + block_size - 1) / block_size;
    compute_sine<<<num_blocks, block_size>>>(d_input, d_output, size);
 
    cudaMemcpy(output, d_output, bytes, cudaMemcpyDeviceToHost);
    for (int i = 0; i < size; i++) {
        printf("sin(%.4f) = %.4f\n", input[i], output[i]);
    }
 
    cudaFree(d_input);
    cudaFree(d_output);
    free(input);
    free(output);
    return 0;
}
