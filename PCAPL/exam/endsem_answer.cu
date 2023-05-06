#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cuda.h>

__global__ void modify(char* s,int* pos, char m, int n)
{
  int idx=blockIdx.x*blockDim.x*blockDim.y+threadIdx.y*blockDim.x+threadIdx.x;
  int start=pos[idx]+1;
  int end=pos[idx+1];
  if(idx<pos[idx+1]-pos[idx])
  {
    if(m=='R')
    {
      for(int i=0;i<n;i++)
      {
        char temp=s[end-1];
        for(int j=end-2;j>=start;j--)
        {
          s[j+1]=s[j];
        }
        s[start]=temp;
      }
    }
    else if(m=='L')
    {
      for(int i=0;i<n;i++)
      {
        char temp=s[start];
        for(int j=start;j<end;j++)
        {
          s[j]=s[j+1];
        }
        s[end-1]=temp;
      }
    }
  }
}

int main()
{
  char *s, c;
  int n;
  s=(char*)malloc(sizeof(char)*100);
  printf("Enter the string : ");
  scanf("%[^\n]%*c",s); //keep scanning every character(*c -> zero or more) until it's not '\n'
  
  printf("Enter the rotation orientation : ");
  scanf("%c",&c);
  
  printf("Enter the number of rotations : ");
  scanf("%d",&n);
  
  int l=strlen(s);
  int b[100],k=0;
  b[k++]=-1;
  for(int i=0;i<l;i++)
  {
    if(s[i]==' ')
      b[k++]=i;
  }
  b[k++]=l;
  printf("Total number of words = %d",k-1);
  printf("\nLength of each word = ");
  int maxi=-1;
  for(int i=0;i<k-1;i++)
  {
    int d=b[i+1]-b[i];
    if(d>maxi)
      maxi=d;
    printf("%d ",d-1);
  }
  
  printf("\nLength of the longest word = %d\n",maxi-1);
  
  char *d_s;
  int *d_pos;
  cudaMalloc((void**)&d_s,sizeof(char)*l);
  cudaMalloc((void**)&d_pos,sizeof(int)*k);
  cudaMemcpy(d_s,s,sizeof(char)*l,cudaMemcpyHostToDevice);
  cudaMemcpy(d_pos,b,sizeof(int)*k,cudaMemcpyHostToDevice);
  dim3 block(2,maxi/2+1,1);
  dim3 grid(k,1,1);
  
  modify<<<grid,block>>>(d_s,d_pos,c,n);
  char* result;
  result=(char*)malloc(sizeof(char)*l);
  cudaMemcpy(result,d_s,sizeof(char)*l,cudaMemcpyDeviceToHost);
  result[l]='\0';
  printf("Output string : %s\n",result);
 
  cudaFree(d_pos);
  cudaFree(d_s);
  free(result);
  
  return 0;
}      
