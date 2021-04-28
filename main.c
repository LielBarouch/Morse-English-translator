#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"function.h"
#define MAX_STR 265 



void main()
{
	morse_table table[] = { {". ---",'A'},
						  {"--- . . .",'B'},
						 {"--- . --- .",'C'},
						 {"--- . .",'D'},
						 {".",'E'},
						 {". . --- .",'F'},
						 {"--- --- .",'G'},
						 {". . . .",'H'},
						 {". .",'I'},
						 {"--- . . .",'J'},
						 {"--- . ---",'K'},
						 {". --- . .",'L'},
						 {"--- ---",'M'},
						 {"--- .",'N'},
						 {"--- --- ---",'O'},
						 {". --- --- .",'P'},
						 {"--- --- . ---",'Q'},
						 {". --- .",'R'},
						 {". . .",'S'},
						 {"---",'T'},
						 {". . ---",'U'},
						 {". . . ---",'V'},
						 {". --- ---",'W'},
						 {"--- . . ---",'X'},
						 {"--- . --- ---",'Y'},
						 {"--- --- . .",'Z'},
						 {". --- --- --- ---",'1'},
						 {". . --- --- ---",'2'},
						 {". . . --- ---",'3'},
						 {". . . . ---",'4'},
						 {". . . . .",'5'},
						 {"--- . . . .",'6'},
						 {"--- --- . . .",'7'},
						 {"--- --- --- . .",'8'},
						 {"--- --- --- ---.",'9'},
						 {"--- --- --- --- ---",'0'}, };
	

	comd comd_str;
	char user_input[MAX_STR];
	int i;
	FILE* morse_file, * eng_file;

	char coomand_1[MAX_STR] = "load_cmf_and_print_text";
	char command_2[MAX_STR] = "text_save_and_cmf_load";
	char command_3[MAX_STR] = "load_text_and_print_cmf";
	char command_4[MAX_STR] = "cmf_save_and_text_load";
	char command_5[MAX_STR] = "translate_text_and_print_cmf";
	char command_6[MAX_STR] = "translate_cmf_and_print_text";
	char command_7[MAX_STR] = "print_format_name";
	char command_8[MAX_STR] = "quit";

	printf("----Welcom to morse translator----\n");

	gets(user_input);

	split_input(&user_input, &comd_str);

	if (strcmp(comd_str.command, command_5)==0)
	{
		translate_text_and_print_cmf(comd_str.source , &table);
	}


	
}
	