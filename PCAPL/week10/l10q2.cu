    #include <stdio.h>
    #include <cuda.h>
    #include <math.h>

    __global__ void MatModify(int *a,int *c,int n)
    {
        int ele=blockIdx.x*blockDim.x + threadIdx.x;
        c[ele]=1;
        for(int i=0;i<blockIdx.x+1;i++)
        c[ele]*=a[ele];
    }

    int main()
    {
        int n, m;
        printf("Enter dimensions of matrix: ");
        scanf("%d%d", &m, &n);
        int a[m][n],c[m][n];
        printf("Enter the array elements : \n");
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++) 
            scanf("%d",&a[i][j]);
        }

        int *d_a,*d_c,*a1;
       
        size_t asize;
        asize = m*n*sizeof(int);
        cudaMalloc((void**)&d_a,asize);
        cudaMalloc((void**)&d_c,asize);
        cudaMemcpy(d_a,a,asize,cudaMemcpyHostToDevice);
        a1 = (int*)malloc(asize);

        MatModify<<<m,n>>>(d_a,d_c,n);
        cudaMemcpy(a1,d_c,asize,cudaMemcpyDeviceToHost);
        int k=0;
        printf("Modified matrix:\n");
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++) 
            {
                c[i][j]=a1[k++];
                printf("%d ",c[i][j]);
            }
            printf("\n");
        }

        cudaFree(d_a);cudaFree(d_c);
        return 0;
    }

