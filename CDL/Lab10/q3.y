%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
extern FILE *yyin;
%}

%token NUM OP NL

%%
input: input line 
| 
;
line: NL
| exp NL 
;
exp: NUM 
| exp exp OP
;
%%

int yyerror(char *msg)
{
    printf("Invalid Expression\n");
    return 1;
}

void main()
{
    printf("Enter the expression : ");
    yyin=fopen("in3.txt","r");
    do{
        if(yyparse())
        {
            printf("\nFailure");
            exit(0);
        }
    }while(!feof(yyin));
    printf("Success");
}