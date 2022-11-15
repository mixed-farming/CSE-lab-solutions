// How do you resize and release memory using realloc?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *ch = (char *)malloc(strlen("Hello") * sizeof(char));
    strcpy(ch, "Hello");
    printf("%s\n", ch);
    ch = (char *)realloc(ch, strlen("Hello world") * sizeof(char));
    strcpy(ch, "Hello world");
    printf("%s\n", ch);
    return 0;
}
// Hello
// Hello world
