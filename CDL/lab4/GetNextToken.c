#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "space_remover.h"
#include "preprocess_remover.h"
#define MAX_SIZE 20

typedef struct
{
	unsigned int row, col;
	char token_name[100];
} token;

char keywords[32][10] = {"auto", "double", "int", "struct", "break", "else", "long", "switch", "case", "enum", "register",
						 "typedef", "char", "extern", "return", "union", "const", "float", "short", "unsigned", "continue", "for", "signed", "void",
						 "default", "goto", "sizeof", "volatile", "do", "if", "static", "while"};

char symbols[] = {'=', '<', '>', '!', '+', '-', '*', '/', '%', '(', ')', '{', '}', '[', ']', ',', ';'};

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

void printToken(token t, FILE *fptr)
{
	char buf[256];
	sprintf(buf, "<%s,%d,%d>", t.token_name, t.row, t.col);
	fputs(buf, fptr);
}

void getNextToken(FILE *fptr1, FILE *fptr2)
{
	int r = 1, c = 1, i;
	char ch = fgetc(fptr1), buf[256], ch2;
	while (ch != EOF)
	{
		i = 0;
		buf[0] = '\0';
		c++;
		token t;
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
			t.row = r;
			t.col = (--c);
			if (compKey(buf) == 1)
				strcpy(t.token_name, buf);
			else
				strcpy(t.token_name, "id");
			printToken(t, fptr2);
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
    FILE *fptr1,*fptr2;
    fptr1 = fopen("process_output.c", "r");
	fptr2 = fopen("token_stream.txt", "w");
	getNextToken(fptr1, fptr2);
	fclose(fptr1);
	fclose(fptr2);
	printf("Tokens generated in token_stream.txt\n");
    return 0;
}