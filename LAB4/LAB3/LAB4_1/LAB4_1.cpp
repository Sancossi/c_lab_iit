/*
��� ������� ������ ���������� ��������� ��� �������: ����, ���������� �������, ������. 
*/

/*

�������� ���������������� �������, �������� ��������� ���� ������. 
������� � � � ������������, ��������� ������ ��������� ��������� calloc() ��� malloc(), ��������� � ��������� ������� ������ ����� ���������. 
������������� ������� ��������� �� ��������, ��� ������� ������ �� ����� �������.
*/

/*
������ ��� ������� �(M) � �(M). 
� ������ �� �������� ����� ���������� �������� � ������� ��� �� ���� ��������� ��������. 
�� ������ ������� �������� � ��������������� �������.
*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

void inputArray(int*, int);// ���� �������
void modifyArray(int*,int); // ��������� �� ������� ������������� ����� ���������� � ���
void printArray(int*,int); // ����� ������� �� ������

void main()
{

	/**/
	setlocale(LC_CTYPE, "Russian");
	
	int lenght;

	puts("������� ������ ������� A:");

	scanf("%d", &lenght);
	int* a = (int*) malloc(sizeof(int) * lenght);
	int* testarray = (int*) malloc(sizeof(int) * lenght);
	inputArray(a, lenght);
	printArray(a, lenght);
	modifyArray(a, lenght);
	printArray(a, lenght);
	puts("������� ������ ������� B:");

	scanf("%d", &lenght);
	
	int* b = (int*) malloc(sizeof(int) * lenght);
	inputArray(a, lenght);
	printArray(a, lenght);
	modifyArray(a, lenght);
	printArray(a, lenght);
	

	free(testarray);

	getch();
	return ;
}

void printArray(int* a, int lenght)
{
	if(a != NULL)
	{
		puts("���� ��������� �������");
		for(int i = 0; i < lenght; i++)
		{
			printf("%d \n", *(a+i));
		}
		printf("\n");
	}
}

void inputArray(int* a, int lenght)
{
	if(a != NULL)
	{
	
		
		puts("������� �������� �������");

		for(int i = 0; i < lenght; i++) 
		{
			scanf("%d", (a+i));
		}

	}
}

void modifyArray(int* a, int lenght)
{
	if(a != 0)
	{
		puts("�����������");
		int max = 0;
		for(int i = 0; i < lenght; i++)
		{
			if(max < *(a+i))
			{
				max = *(a+i);
				printf("max:%d",max);
			}
		}

		for(int i = 0; i < lenght; i++)
		{
			*(a+i) -= max;
		}
	}
}