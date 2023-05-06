 #include<stdio.h>
 #include "cuda_runtime.h"
 #include "device_launch_parameters.h"
 __global__ void calc(float* ma, float* a, int mw, float* res){
   int m = blockDim.y, n = blockDim.x, i = threadIdx.y, j = threadIdx.x, sum = 0;
   for(int k = i - mw / 2, p = 0; k <= i + mw / 2; k++, p++)
   for(int l = j - mw / 2, q = 0; l <= j + mw / 2; l++, q++)
   if(k >= 0 && k < m && l < n && l >= 0)
   sum += ma[p * mw + q] * a[k * n + l];
   res[i * n + j] = sum;
 }
 int main(){
   int m, n, mw;
   printf("Enter the array dimensions : ");
   scanf("%d%d", &m, &n);
   float a[m * n], *d_a, res[m * n], *d_res;
   printf("Enter the matrix elements: \n");
   for(int i = 0; i < m * n; i++) scanf("%f", &a[i]);
   printf("Enter the mask width: ");
   scanf("%d", &mw);
   float ma[mw * mw], *d_ma;
   printf("Enter the mask matrix elements: \n");
   for(int i = 0; i < mw * mw; i++) scanf("%f", &ma[i]);
   cudaMalloc((void**)&d_a, sizeof(float) * m * n);
   cudaMalloc((void**)&d_ma, sizeof(float) * mw * mw);
   cudaMalloc((void**)&d_res, sizeof(float) * m * n);
   cudaMemcpy(d_a, &a, sizeof(float) * m * n, cudaMemcpyHostToDevice);
   cudaMemcpy(d_ma, &ma, sizeof(float) * mw * mw, cudaMemcpyHostToDevice);
   dim3 bl(n, m);
   calc <<< 1, bl >>> (d_ma, d_a, mw, d_res);
   cudaMemcpy(&res, d_res, sizeof(float) * m * n, cudaMemcpyDeviceToHost); 
   printf("Resultant matrix is :\n");
   for(int i = 0; i < m; i++){
     for(int j = 0; j < n; j++) printf("%f ", res[i * n + j]);
     printf("\n");
   }
   cudaFree(d_a);
   cudaFree(d_ma);
   cudaFree(d_res);
   return 0;
 }
