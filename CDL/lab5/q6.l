%{
    #include <ctype.h>
    char c;
%}

%%
[A-Z] {
    c=tolower(yytext[0]);
    fprintf(yyout,"%c",c);
}
\/\/(.*) {
    fprintf(yyout,"%s",yytext);
}			
\/\*(.*\n)*.*\*\/  {
    fprintf(yyout,"%s",yytext);
}
%%

int yywrap()
{}

int main() 
{ 
    yyin=fopen("input2.c","r");
    yyout=fopen("output2.c","w");
    yylex();
    return 0; 
}