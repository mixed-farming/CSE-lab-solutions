%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "q1.tab.h"
%}

%%
[0-9]+ {printf("%s\n",yytext);
        return NUMBER;
        }
\n {return NL;}
"int" {return INT;}
[a-zA-Z]+ {
    printf("%s\n",yytext);
    return ID;
      }
";" {return SS;}
"," {return CO;}
%%

int yywrap()
{
    return 1;
}