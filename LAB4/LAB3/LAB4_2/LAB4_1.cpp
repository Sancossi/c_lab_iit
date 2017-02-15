/*
�������� ���������������� �������, �������� ��������� ���� ������. 
������ ��������� � ������������ ������� ������ �������� new. 
��� ��������� � ��������� ������� ��������������� ������������ �������� � ����������� (��������� ���������). 
������������� ������� ��������� �� ��������, ��� ������� ������ �� ����� �������.

� ���������� �������, ��������� �� n �������� � ���������� ���������, ���������:
*/

/*
����� ��������� �������, ������������� ����� ������ � ��������� �������������� ����������;
*/


#include <stdio.h>
#include <locale.h>
#include <conio.h>

void inputArray(int*, int);
void printArray(int*, int);
int getSum(int*, int);

void main()
{
	setlocale(LC_CTYPE, "Russian");

	puts("������� ������ �������:");
	
	int lenght;

	scanf("%d", &lenght);
	if(lenght <= 0)
	{
		puts("�������� ������ �������");
		return;
	}

	int* a = new int[lenght];
	if(a==NULL)
	{
		puts("������ ��������� ������");
		return;
	}

	inputArray(a, lenght);
	printArray(a, lenght);
	printf("\n����� ��������� ����� %d\n", getSum(a, lenght));
	delete[]a;
}


void inputArray(int* a, int lenght)
{
	puts("���� �������.");
	for(int i=0; i < lenght; i++)
	{
		printf("\n������� %d ������� �������: ", i);
		scanf("%d", a+i);
	}

}

void printArray(int* a, int lenght)
{
	puts("����� �������");
	for(int i = 0; i < lenght; i++)
	{
		printf("%d : %d\n",i, *(a+i));
	}

}

int getSum(int* a, int lenght)
{
	int firstElement = -1;
	int lastElement = 0;
	int result = 0;
	for(int i = 0; i < lenght; i++)
	{
		if(*(a+i) > 0)
		{
			firstElement = i;
			break;
		}
	}
	if (firstElement == -1) 
	{
		puts("������. ��� �������� ������������ ��� ����� ����");
		getch();
		return 0;
	}
	printf("\n������ ������������� ������� ������. ������: %d\n", firstElement);
	for(int i = lenght - 1; i > -1; i--)
	{
		if(*(a+i) > 0)
		{
			lastElement = i;
			break;
		}
	}
	printf("\��������� ������������� ������� ������. ������: %d\n", lastElement);

	for(int i = firstElement; i <= lastElement; i++)
	{
		result += (*(a+i));
	}

	return result;
}