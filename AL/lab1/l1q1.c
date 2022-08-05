#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b, int *x)
{
  for (int i = (a > b ? b : a); i > 0; i--)
  {
    (*x)++;//opcount increment
    if (a % i == 0 && b % i == 0)
    {
      return i;//gcd
    }
  }
}

int main()
{
  int m, n;
  printf("Enter two values : ");//inputs
  scanf("%d %d", &m, &n);
  int x = 0; //opcount
  int result = gcd(m, n, &x);
  printf("\nGCD is %d and the Opcount is  %d\n", result, x);
}