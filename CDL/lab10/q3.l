%{
int pos=0, neg=0,fpos=0,fneg=0;
%}

%%
[0-9]+ {pos++;} // positive number
-[0-9]+ {neg++;} // negative number
[0-9]+\.[0-9]+ {fpos++;} //floating positive number
-[0-9]+\.[0-9]+ {fneg++;} //floating negative number
. ;
%%

int yywrap(){}

int main()											
{
    printf("Enter numbers : \n");
    yylex();
    printf("Number of positive numbers = %d\n",pos);
    printf("Number of floating positive numbers = %d\n",fpos);
    printf("Number of negative numbers = %d\n",neg);
    printf("Number of floating negative numbers = %d\n",fneg);
    return 0;
}
