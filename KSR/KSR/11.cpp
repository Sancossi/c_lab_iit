/*11  С помощью текстового редактора БЛОКНОТ создать файл, 
содержащий текст, длина которого не превышает 1000 символов 
(длина строки текста не должна превышать 70 символов).
Файл должен иметь расширение DAT. 
Написать программу, которая:
-	выводит текст на экран дисплея;
-	определяет количество букв “a” в последнем слове текста.
*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <process.h>

#define MAX_FILE_SIZE 1000
#define FILE_NAME "FILE.TXT"
void readfile(char *t)
{
	setlocale(LC_CTYPE, "Russian");
	int i = 0; // индекс начала последнего слова
	int sp = 0;
	int n = 0; // число символов 

	char *d = "a";

	// открываем файл
	FILE *f;
	if(!(f = fopen(FILE_NAME, "r+")))
	{
		puts("Ошибка открытия файла");
		return;
	}
	
	// чтение файла 
	// входим в бесконечный цикл
	for(;;)
	{
		char c = fgetc(f);
		if(c == EOF)
		{
			if(feof(f) != 0) break;
		}

		else if(c == '\n') continue; // если конец строки 
		else if(c == ' ') sp = i;
		t[i] = c;
		printf("%c", t[i++]); 
		
	}
	for(;;)
	{
		if(t[++sp] == *d) n++;
		else if(sp = i) break;
	}
	printf("\n Все прочитано : %d символов\n В последнем слове %d символов ", i, n);
	fclose(f);
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char *text = new char[MAX_FILE_SIZE];
	readfile(text);
	delete[] text;
	_getch();
}