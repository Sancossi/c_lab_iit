// lab7_1.cpp : main project file.

#include "stdafx.h"
#include "windows.h"
#include <stdio.h>
#include <locale.h>
#include <conio.h>

using namespace System;

#define FILENAME "FILE.TXT"

int menu();
void writeFile(char*);
char readFile();
void codeAndWriteFile(char*);
void encodeAndWriteFile(char*);

void main()
{
	setlocale(LC_CTYPE, "Russian");

	while(menu()!=5);

	getch();
}

int menu()
{
	int choise;
	
		choise = 0;
		puts("ћеню программы:");
		puts("1 Ц —формировать с клавиатуры строку  и записать в файл");
		puts("2 Ц —читать строку из файла и распечатать");
		puts("3 Ц «ашифровать строку и записать в файл");
		puts("4 Ц –асшифровать строку и записать в файл");
		puts("5 Ц ¬ыход");
		printf("¬ыберите пункт меню: ");
		scanf("%d", &choise);
		switch(choise)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			return 5;
			break;
		default:
			puts("”казан не правильный пункт меню. ѕопробуйте снова");
			break;
		}
	return 0;
}