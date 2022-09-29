#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct token
{
    char name[100];
    int arg;
} token;

int main()
{
    FILE *fptr1, *fptr2;
    token t[100];
    char keywords[8][15] = {"function", "global", "if", "print", "while", "foreach", "as"};
    int c = 0, i, flag;
    char buf[100], ch, ch2;
    fptr1 = fopen("input.txt", "r");
    fptr2 = fopen("output.txt", "w+");
    if (!fptr1 || !fptr2)
    {
        printf("File cannot be opened");
        exit(1);
    }
    ch = fgetc(fptr1);
    while (ch != '\n')
        ch = fgetc(fptr1); // removing php
    ch = fgetc(fptr1);
    while (ch != EOF)
    {
        fputc(ch, fptr2);
        ch = fgetc(fptr1);
    }
    fclose(fptr1);
    fclose(fptr2);
    fptr1 = fopen("output.txt", "r");
    ch = fgetc(fptr1);
    printf("Tokens are generated in output.txt\n");
    while (ch != EOF)
    {
        i = 0;
        buf[i] = '\0';
        if (ch == '\n' || ch == ' ')
            ch = fgetc(fptr1);
        else if (isalpha(ch) != 0 || ch == '_' || ch == '$')
        {
            buf[i++] = ch;
            ch2 = fgetc(fptr1);
            flag = 0;
            while (isalnum(ch2) != 0 || ch2 == '_')
            {
                buf[i++] = ch2;
                ch2 = fgetc(fptr1);
            }
            buf[i] = '\0';
            ch = ch2;
            for (int j = 0; j < 7; j++)
            {
                if (strcmp(buf, keywords[j]) == 0)
                {
                    printf("%s - Keyword\n", buf);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) // identifier
            {
                strcpy(t[c].name, buf);
                printf("%s - ID\n", buf);
                // ch = fgetc(fptr1);
                if (ch == '(')
                {
                    // printf("%c - Symbol\n",ch2);
                    int count = 0;
                    ch2 = fgetc(fptr1);
                    if (ch2 == ')')
                    {
                        printf("%c - Symbol\n",ch2);
                        t[c].arg = count;
                        c++;
                    }
                    else
                    {
                        count = 1;
                        while (ch2 != ')')
                        {
                            if (ch2 == ',')
                            {
                                count++;
                            }
                            ch2 = fgetc(fptr1);
                        }
                        t[c].arg = count;
                        count = 0;
                        c++;
                    }
                }
            }
        }
        else if (ch == '"')
        {
            do
            {
                buf[i++] = ch;
                ch = fgetc(fptr1);
            } while (ch != '"');
            buf[i++] = ch;
            buf[i] = '\0';
            printf("%s - String Literal\n", buf);
            ch = fgetc(fptr1);
        }
        else if (ch == '\'')
        {
            do
            {
                buf[i++] = ch;
                ch = fgetc(fptr1);
            } while (ch != '\'');
            buf[i++] = ch;
            buf[i] = '\0';
            printf("%s - Character Literal\n", buf);
            ch = fgetc(fptr1);
        }
        else if (ch == '<' || ch == '=' || ch == '+' || ch == '>')
        {
            buf[i++] = ch;
            ch2 = fgetc(fptr1);
            if (ch2 == '=')
                buf[i++] = ch2;
            buf[i] = '\0';
            printf("%s - Operator\n", buf);
            ch = ch2;
        }
        else if (isdigit(ch) != 0)
        {
            buf[i++] = ch;
            ch2 = fgetc(fptr1);
            while (isdigit(ch2) != 0)
            {
                buf[i++] = ch2;
                ch2 = fgetc(fptr1);
            }
            buf[i] = '\0';
            printf("%s - Number\n", buf);
            ch = ch2;
        }
        else
        {
            buf[i++] = ch;
            buf[i] = '\0';
            printf("%s - Symbol\n", buf);
            ch = fgetc(fptr1);
        }
    }

    printf("\nSymbol table for function : \n");
    printf("\n\t\tFunction name\t\targuments count\n\n");
    for (i = 0; i < c; i++)
        printf("%30.30s\t\t%5.1d\n", t[i].name, t[i].arg);

    return 0;
}
