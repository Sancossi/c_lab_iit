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
		puts("���� ���������:");
		puts("1 � ������������ � ���������� ������  � �������� � ����");
		puts("2 � ������� ������ �� ����� � �����������");
		puts("3 � ����������� ������ � �������� � ����");
		puts("4 � ������������ ������ � �������� � ����");
		puts("5 � �����");
		printf("�������� ����� ����: ");
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
			puts("������ �� ���������� ����� ����. ���������� �����");
			break;
		}
	return 0;
}