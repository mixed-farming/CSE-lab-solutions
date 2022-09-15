#include<stdio.h>
float add(float x,float y)
{
float s;
s=x+y;
return s;
}
void main()
{
float a,b,sum; //Single line comment
a=1.0;
b=1e-2;
/*Multi line
comment*/
sum=add(a,b);
printf("Sum=%.2f\n",sum);
}
