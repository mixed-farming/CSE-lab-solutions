
int Compare(int a,int b)
{
 if(a<b||a<0)
 return 1;
 else 
 return 0;
}
int Equal(int a, int b)
{
 if(a==b)
 return 1;
 else 
 return 0;
}
int main()
{
 int a=3,b=2e+3;;
 char c;
 float k;
 if(Compare(a,b))
 printf("yes\n");
 else if(Equal(a,b))
 printf("equal\n");
 else
 printf("no\n");

 return 0;
}

