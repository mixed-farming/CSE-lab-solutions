// WAP to allocate memory dynamically
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *ch = (char *)malloc(strlen("Hello world") * sizeof(char));
    strcpy(ch, "Hello world");
    printf("%s\n", ch);
    return 0;
}
// Hello world
