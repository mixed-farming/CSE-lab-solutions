/*
after removing left recursion

S->a|>|(T)
T->ST'
T'->,ST'|ε

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[100];
int i=0;
void S();
void T();
void Tdash();

void invalid()
{
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
    if(buf[i]=='a'||buf[i]=='>')
    {
        i++;
        return;
    }
    else if(buf[i]=='(')
    {
        i++;
        T();
        if(buf[i]==')')
        {
            i++;
            return;
        }
        else 
            invalid();
    }
    else
        invalid();
}

void T()
{
    S();
    Tdash();
}

void Tdash()
{
    if(buf[i]==',')
    {
        i++;
        S();
        Tdash();
    }
    //else Tdash -> ε
}

int main()
{
    printf("Enter the input string : ");
    scanf("%s",buf);
    S();
    if(buf[i]=='$')
        valid();
    else 
        invalid();
    return 0;
}