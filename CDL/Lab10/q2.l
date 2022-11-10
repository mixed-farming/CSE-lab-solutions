%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "q2.tab.h"
%}

%%
[0-9]+ {printf("%s\n",yytext);
        return NUMBER;
        }
"if" {return IF;}
"else" {return ELSE;}
[(,)] {return PARENTHESIS;}
[{,}] {return BRACE;}
[>,<,"<="] {return INEQUALITY;}
"<="|">="|"!="|"==" {return INEQUALITY;}

%%

int yywrap()
{
    return 1;
}
