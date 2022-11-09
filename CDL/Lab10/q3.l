%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "q3.tab.h"
%}

%%
[0-9]+ {printf("%s\n",yytext);
        return NUM;
        }
\n {return NL;}
[+,*,-,/,^] {return OP;}
%%

int yywrap()
{
    return 1;
}