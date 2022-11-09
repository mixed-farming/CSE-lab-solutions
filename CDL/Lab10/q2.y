%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
extern FILE *yyin;
%}

%token NL IF NUMBER ELSE BRACE INEQUALITY PARENTHESIS

%%
stmt: IF PARENTHESIS CONDITION PARENTHESIS BODY
| IF PARENTHESIS CONDITION PARENTHESIS BODY ELSE BODY
;
CONDITION: NUMBER INEQUALITY NUMBER
;
BODY: BRACE BRACE
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
    yyin=fopen("in2.txt","r");
    do{
        if(yyparse())
        {
            printf("\nFailure");
            exit(0);
        }
    }while(!feof(yyin));
    printf("Success");
}