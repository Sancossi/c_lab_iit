/*
Во всех заданиях предусмотреть захват и освобождение динамической памяти (операции new, delete), 
решение оформить в виде отдельной функции, которой передается исходная строка. 
На печать вывести исходную и преобразованную строки.

4. Ввести строку символов, если ее длина >6, выделить подстроку после последнего пробела.

*/

#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

void f(char*);

void main()
{
	setlocale(LC_ALL, "Russian");
    int length;
	int size = 0;
	char *text;
	puts("Введите длинну строки: ");
	scanf("%d", &length);
	if(length <= 0) 
	{
		puts("Значение длинны должно быть положительным.");
		return;
	}
	text = new char[++length];
	if(text == NULL)
	{
		puts("Не хватает памяти для завершения операции");
		return;
	}
	size = sizeof(char) * length;
	fflush(stdin);
	fgets(text, size, stdin);

	f(text);
	
	delete[] text;
	getch();

}

void f(char *s)
{
	
	const char c = ' ';
	char *ret = strrchr(s, c);
	printf("%s", ret+1);
}
