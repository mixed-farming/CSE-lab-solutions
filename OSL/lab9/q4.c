// How do you guarantee releasing memory using free?
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *ch = (char *)malloc(strlen("Hello world") * sizeof(char));
    strcpy(ch, "Hello world");
    printf("Before freeing: %s\n", ch);
    free(ch);
    printf("After freeing: %s\n", ch);
    return 0;
}
// Before freeing: Hello world
// After freeing:
