
#pragma warning(disable:4996)
#include<stdio.h>
#pragma ones
#include<stdlib.h>
#include<string.h>
#define MAX_CHAR 256



typedef struct morse
{
	char* morse;
	char ascii;
} morse_table;

typedef struct commands
{
	char *command;
	char *source;
	char *dest;
}comd;

int split_input();
void translate_text_and_print_cmf();
