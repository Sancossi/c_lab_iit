/*
�� ���� �������� ������������� ������ � ������������ ������������ ������ (�������� new, delete), 
������� �������� � ���� ��������� �������, ������� ���������� �������� ������. 
�� ������ ������� �������� � ��������������� ������.

4. ������ ������ ��������, ���� �� ����� >6, �������� ��������� ����� ���������� �������.

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
	puts("������� ������ ������: ");
	scanf("%d", &length);
	if(length <= 0) 
	{
		puts("�������� ������ ������ ���� �������������.");
		return;
	}
	text = new char[++length];
	if(text == NULL)
	{
		puts("�� ������� ������ ��� ���������� ��������");
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
