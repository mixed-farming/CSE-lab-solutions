/*

S->UVW
U->(S)|aSb|d
V->aV|ε 
W->cW|ε

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[100];
int i=0;
void S();
void U();
void V();
void W();

void invalid()
{
    //printf("String failed at %c\n", buf[i]); // to debug
    printf("*****FAILURE*****\n");
    exit(1);
} 

void valid()
{
    printf("*****SUCCESS*****\n");
    exit(1);
}

void S()
{
    U();
    V();
    W();
}

void U()
{
    if(buf[i]=='(')
    {
        i++;
        S();
        if(buf[i]==')')
        {
            i++;
            return;
        }
        else
        {
            invalid();
        }
    }
    else if(buf[i]=='a')
    {
        i++;
        S();
        if(buf[i]=='b')
        {
            i++;
            return;
        }
        else
        {
            invalid();
        }
    }
    else if(buf[i]=='d')
    {
        i++;
        return;
    }
    else
    {
        invalid();
    }
}

void V()
{
    if(buf[i]=='a')
    {
        i++;
        V();
    }
    //else V->ε
}

void W()
{
    if(buf[i]=='c')
    {
        i++;
        W();
    }
    //else W->ε
}

int main()
{
    printf("Enter the input string : ");
    scanf("%s",buf);
    S();
    if(buf[i]=='$')
        valid();
    else 
    {
        invalid();
    }
    return 0;
}