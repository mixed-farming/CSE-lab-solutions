#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    READ("%d",&x);
    WRITE("The value of the number = %d",x);
    return 0;
}