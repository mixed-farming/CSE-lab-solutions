#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "space_remover.h"
#include "preprocess_remover.h"

typedef struct
{
    unsigned int row, col;
    char token_name[100];
} token;

typedef struct
{
    char lexeme[100], DType[10], RType[10], size[2];
} entry;

typedef struct global
{
    entry e, local[50];
} global;

entry SymTab[100];
global globe[20];
int count = 0, num = 0; // No. of symbol table entries & preprocessor directives

char keywords[32][10] = {"auto", "double", "int", "struct", "break", "else", "long", "switch", "case", "enum", "register",
                         "typedef", "char", "extern", "return", "union", "const", "float", "short", "unsigned", "continue", "for", "signed", "void",
                         "default", "goto", "sizeof", "volatile", "do", "if", "static", "while"};

char symbols[] = {'=', '<', '>', '!', '+', '-', '*', '/', '%', '(', ')', '{', '}', '[', ']', ',', ';'};
char ipop[6][10] = {"printf", "scanf", "gets", "puts", "getline", "putline"};

int compKey(char buf[])
{
    for (int i = 0; i < 32; i++)
        if (strcmp(buf, keywords[i]) == 0)
            return 1;
    return 0;
}

int compSym(char ch)
{
    for (int i = 0; i < 17; i++)
        if (ch == symbols[i])
            return 1;
    return 0;
}

int compIPOP(char buf[])
{
	for (int i = 0; i < 32; i++)
		if (strcmp(buf, ipop[i]) == 0)
			return 1;
	return 0;
}

void printToken(token t, FILE *fptr)
{
    char buf[256];
    sprintf(buf, "<%s,%d,%d>", t.token_name, t.row, t.col);
    fputs(buf, fptr);
}

void copy(entry *dest, entry *src)
{
    strcpy(dest->lexeme, src->lexeme);
    strcpy(dest->size, src->size);
    strcpy(dest->DType, src->DType);
    strcpy(dest->RType, src->RType);
}
void display(entry ent)
{
    printf("%s\t%s\t%s\t%s\n", ent.lexeme, ent.DType, ent.size, ent.RType);
}

void getNextToken(FILE *fptr1, FILE *fptr2)
{
	int r = 1, c = 1, i;
	char ch = fgetc(fptr1), buf[128], ch2;
	token t, t1, t2;
	while (ch != EOF)
	{
		i = 0;
		buf[0] = '\0';
		c++;
		if (ch == '\n')
		{
			r++;
			c = 1;
			fputc(ch, fptr2);
			ch = fgetc(fptr1);
			continue;
		} // To modify row and col
		else if (ch == ' ')
		{
			ch = fgetc(fptr1);
			continue;
		}
		else if (compSym(ch) == 1) // Relational and arithmetic operators, and brackets, comma, and semi-colon
		{
			buf[i++] = ch;
			ch2 = fgetc(fptr1);
			if (ch2 == '=')
				buf[i++] = ch2;
			buf[i] = '\0';
			t.row = r;
			t.col = (--c);
			strcpy(t.token_name, buf);
			printToken(t, fptr2);
			c += strlen(buf);
			ch = ch2;
			continue;
		}
		else if (ch == '|' || ch == '&') // Logical operators
		{
			buf[i++] = ch;
			ch = fgetc(fptr1);
			if (ch == '|' || ch == '&')
				buf[i++] = ch;
		}
		else if (ch == '\"') // String literals
		{
			do
			{
				buf[i++] = ch;
				ch = fgetc(fptr1);
			} while (ch != '\"');
			buf[i++] = ch;
		}
		else if (isdigit(ch) != 0) // Numeric constants
		{
			buf[i++] = ch;
			ch2 = fgetc(fptr1);
			while (isdigit(ch2) != 0)
			{
				buf[i++] = ch2;
				ch2 = fgetc(fptr1);
			}
			if (ch2 == '.')
				do
				{
					buf[i++] = ch2;
					ch2 = fgetc(fptr1);
				} while (isdigit(ch2) != 0);
			if (ch2 == 'E' || ch2 == 'e')
			{
				buf[i++] = ch2;
				ch2 = fgetc(fptr1);
				if (ch2 == '+' || ch2 == '-')
				{
					buf[i++] = ch2;
					ch2 = fgetc(fptr1);
				}
				while (isdigit(ch2) != 0)
				{
					buf[i++] = ch2;
					ch2 = fgetc(fptr1);
				}
			}
			buf[i] = '\0';
			t.row = r;
			t.col = (--c);
			strcpy(t.token_name, buf);
			printToken(t, fptr2);
			c += strlen(buf);
			ch = ch2;
			continue;
		}
		else if (isalpha(ch) != 0 || ch == '_') // Identifiers and Keywords
		{
			buf[i++] = ch;
			ch2 = fgetc(fptr1);
			while (isalnum(ch2) != 0 || ch2 == '_')
			{
				buf[i++] = ch2;
				ch2 = fgetc(fptr1);
			}
			buf[i] = '\0';
			if (compKey(buf) == 1) // Keyword
			{
				t1.row = r;
				t1.col = (--c);
				strcpy(t1.token_name, buf);
				printToken(t1, fptr2);
			}
			else // Identifier
			{
				t2.row = r;
				t2.col = (--c);
				strcpy(t2.token_name, "id");
				printToken(t2, fptr2);
				strcpy(SymTab[count].lexeme, buf);
				char str[2];
				if (compIPOP(buf) == 1)
				{
					c += strlen(buf);
					ch = ch2;
					continue;
				}
				else if (ch2 == '(') // Function
				{
					strcpy(SymTab[count].DType, "Func");
					strcpy(SymTab[count].RType, t1.token_name);
					strcpy(SymTab[count].size, "-");
				}
				else // Variable
				{
					if (strcmp(t1.token_name, "double") == 0)
					{
						sprintf(str, "%ld", sizeof(double));
						strcpy(SymTab[count].size, str);
					}
					else if (strcmp(t1.token_name, "int") == 0)
					{
						sprintf(str, "%ld", sizeof(int));
						strcpy(SymTab[count].size, str);
					}
					else if (strcmp(t1.token_name, "long") == 0)
					{
						sprintf(str, "%ld", sizeof(long));
						strcpy(SymTab[count].size, str);
					}
					else if (strcmp(t1.token_name, "char") == 0)
					{
						sprintf(str, "%ld", sizeof(char));
						strcpy(SymTab[count].size, str);
					}
					else if (strcmp(t1.token_name, "float") == 0)
					{
						sprintf(str, "%ld", sizeof(float));
						strcpy(SymTab[count].size, str);
					}
					else if (strcmp(t1.token_name, "short") == 0)
					{
						sprintf(str, "%ld", sizeof(short));
						strcpy(SymTab[count].size, str);
					}
					else
					{
						c += strlen(buf);
						ch = ch2;
						continue;
					} // to avoid cases like "return sum;" being added to SymTab
					strcpy(SymTab[count].DType, t1.token_name);
					strcpy(SymTab[count].RType, "-");
				}
				count++;
			}
			c += strlen(buf);
			ch = ch2;
			continue;
		}
		else
			buf[i++] = ch; // Special characters
		buf[i] = '\0';
		t.row = r;
		t.col = (--c);
		strcpy(t.token_name, buf);
		printToken(t, fptr2);
		c += strlen(buf);
		ch = fgetc(fptr1);
	}
}

int main()
{
    // executing space function from spaces.h
    space();
    // executing process function from preprocess.h
    process();
    FILE *fptr1, *fptr2;
    int i, j, k, l, f[20], ct = 0, hf, flag;
    fptr1 = fopen("process_output.c", "r");
    fptr2 = fopen("token_stream.txt", "w");
    getNextToken(fptr1, fptr2);
    fclose(fptr1);
    fclose(fptr2);
    printf("Tokens generated in token_stream.txt\n");
    for (i = 0; i <= count - 1; i++) // Remove function calls
    {
        for (j = i + 1; j <= count; j++)
        {
            if (strcmp(SymTab[i].DType, "Func") == 0 && strcmp(SymTab[j].DType, "Func") == 0)
            {
                if (strcmp(SymTab[i].lexeme, SymTab[j].lexeme) == 0)
                {
                    for (k = j; k < count - 1; k++)
                        copy(&SymTab[k], &SymTab[k + 1]);
                    count--;
                }
            }
        }
    }
    for (i = 0; i < count; i++)
    {
        if (strcmp(SymTab[i].DType, "Func") == 0)
        {
            f[ct++] = i;//stroing the position of the functions
        }
    }                        // To get no. and posns. of funcs
    for (k = 0; k < ct; k++) // Remove duplicates within a function
    {
        if ((k + 1) == ct)
            f[k + 1] = count;
        for (i = f[k]; i < f[k + 1] - 1; i++)
        {
            for (j = i + 1; j < f[k + 1]; j++) // Check within an individual function and remove duplicates
            {
                if (strcmp(SymTab[i].RType, "-") == 0 && strcmp(SymTab[j].RType, "-") == 0)
                {
                    if (strcmp(SymTab[i].lexeme, SymTab[j].lexeme) == 0)
                    {
                        for (l = j; l < count - 1; l++)
                            copy(&SymTab[l], &SymTab[l + 1]);
                        count--;
                    }
                }
            }
        }
    }
    ct = 0;
    for (i = 0; i < count; i++)
        if (strcmp(SymTab[i].DType, "Func") == 0)
            f[ct++] = i; // To refresh no. and posns. of funcs.
    f[ct] = count;
    for (i = 0; i < ct; i++)
    {
        copy(&globe[i].e, &SymTab[f[i]]); // Creating global symbol table
        for (j = 0; j < 50; j++)
            strcpy(globe[i].local[j].lexeme, "-"); // Initializing all local entries first
        for (j = f[i] + 1; j < f[i + 1]; j++)      // Creating respective local symbol tables
        {
            hf = 0;
            flag = 0;
            for (k = 0; k < strlen(SymTab[j].lexeme); k++)
                hf += (SymTab[j].lexeme[k] - '0');
            hf %= 50;
            if (strcmp(globe[i].local[hf].lexeme, "-") == 0)
            {
                copy(&globe[i].local[hf], &SymTab[j]);
                continue;
            }
            else
            {
                for (k = hf + 1; k < 50; k++)//checking ahead
                {
                    if (strcmp(globe[i].local[k].lexeme, "-") == 0)
                    {
                        copy(&globe[i].local[k], &SymTab[j]);
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0)//checking behind
            {
                for (k = hf - 1; k >= 0; k--)
                {
                    if (strcmp(globe[i].local[k].lexeme, "-") == 0)
                    {
                        copy(&globe[i].local[k], &SymTab[j]);
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0)//table is full
                printf("%s couldn\'t be inserted\n", SymTab[j].lexeme);
        }
    }
    printf("\nGlobal Symbol Table:\nLexeme\tDType\tSize\tRType\n");
    for (i = 0; i < ct; i++)
        display(globe[i].e);
    for (i = 0; i < ct; i++)
    {
        printf("\nLocal Symbol Table for %s():\nLexeme\tDType\tSize\tRType\n", globe[i].e.lexeme);
        for (j = 0; j < 50; j++)
        {
            if (strcmp(globe[i].local[j].lexeme, "-") == 0)
                continue;
            else
                display(globe[i].local[j]);
        }
    }
    return 0;
}
