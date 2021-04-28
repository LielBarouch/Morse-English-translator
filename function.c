#pragma ones
#pragma warning(disable : 4996)
#include"function.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int split_input(char* str, comd* comd_str)
{

	int i, res;
	int flag = 0;
	int size = 0;
	int k = 0;
	int j;
	int len = 0;
	char str_command[MAX_CHAR];
	int word_num = 0;  //סופר מחרוזת עד הרווח : הראשון זאת הפקודה השני זהקובץ והשלישי גם הקובץ

	len = strlen(str); //אורך המחרוזת שקיבלתי


	res = 0;
	for (i = 0; i < len; i++, size++)
	{
		if (str[i] == ' ' || str[i + 1] == '\0') // או שיש רווח או שהתו הבא הוא סיום מחרוזת
		{
			word_num++;
			if (str[i + 1] == '\0')
			{
				str_command[i] = str[i];
				str_command[i + 1] = '\0';

			}

			if (str[i + 1] != '\0') //אם תו הבא הוא לא סיום המחרוזת 
			{
				str_command[i] = '\0';
				if (strcmp(str_command, "translate_cmf_and_print_text") == 0) { //אם הפקודה שהמשתמש הקליד שווה לפקודה של תרגום לטקסט תחזור ותפרק את המורס בצורה אחרת
					comd_str->command = (char*)malloc((size - 1) * (sizeof(char)));
					strcpy(comd_str->command, str_command);
					return 1;
				}
			}

			if (i - size == 0)
				k = i - size;
			else
				k = i - size + 1;

			switch (word_num)   //בודק אם זאת הפקודה או שם של קובץ ראשון או שם של קובץ שני
			{
			case 1:comd_str->command = (char*)malloc((size - 1) * (sizeof(char)));
				strcpy(comd_str->command, &str_command[k]);
				res = 1;
				break;
			case 2:comd_str->source = (char*)malloc((size - 1) * (sizeof(char)));
				strcpy(comd_str->source, &str_command[k]);
				break;
			case 3:comd_str->dest = (char*)malloc((size - 1) * (sizeof(char)));
				strcpy(comd_str->dest, &str_command[k]);
				flag = 1; //אם הדגל שווה ל1 זאת אומרת שהוכנס שם של קובץ חדש
				break;

			}

			if (str[i + 1] != '\0')
			{
				str_command[i] = ' ';
				if (str[i + 1] == ' ')// בודק אם יש רווחים ומקדם את המחזרוזת עד שנגמרים הרווחים
				{
					i++;
					while (str[i + 1] == ' ')
					{
						i++;
					}

				}
			}
			size = 0;
		}

		else
		{
			str_command[i] = str[i];

		}

	}
	if (!flag) //אם הדגל שווה 0 לא הוכנס שם של קובץ חדש ונציב NULL
	{
		comd_str->dest = (char*)malloc((5) * (sizeof(char)));
		comd_str->dest = "NULL";
	}

	return res;

}

void translate_text_and_print_cmf(comd* str, morse_table formation[])
{
	int i;
	int flag = 0;
	int j;
	int end_of_line = 0;
	int size_of_line = 0;

	size_of_line = strlen(str);//בודק מספר תווים שיש בקובץ

	for (i = 0; i < size_of_line; i++)
	{
		if (str[i] != ' ')//אם התו הוא רווח ,ישאיר את הדגל על 1 ולא יכנס להמשך הפור ויקדם לאות הבאה
		{
			flag = 0;
		}
		for (j = 0; j < 36 && !flag; j++)
		{
			if (formation[j].ascii == str[i])//עושה השוואה בין התו שנימשך מהקובץ לבין המבנה נתונים עד שמוצא את האות
			{
				printf("%s", formation[j].morse);//מדפיס את האות הקוד מורס
				if (str[i + 1] != '\0')//אם לא ניגמר הקובץ בתו הבא ידפיס 3 רווחים
				{
					printf("%c%c%c", ' ', ' ', ' ');

					if (str[i + 1] == ' ')//יבדוק אם התו הבא הוא רווי באותיות באנגלית ואם כן יוסיף עוד 4 רווחים כדי שיהיה 7 רווחים בין מילה למילה
					{
						printf("%c%c%c%c", ' ', ' ', ' ', ' ');
					}
				}
				flag = 1;
			}
		}
	}
}

