/*
�������� ���������, ���������� ���������������� �������, �������� ���������������� ���� ������. 
�� ���� �������� ������������� ������ � ������������ ������������ ������ (calloc ��� malloc). 
�� ������ � ���� ������ ������� �������� ���������� ������. 
������� ������� N � M, �������� ������� ������ � ���������� � ������� main(). 
������������� ������� ��������� � ������, ���� �������� ������ �� ��������� ��������� ������������ ������.

4.	��� ������������� ������������� ������. ���������� ������������ ��������� � ��� �������, ������� �� �������� ������������� ���������.
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

void printAr(int**, int, int);
int f(int**, int, int);

void main()
{
	setlocale(LC_CTYPE, "Russian");

	int n;		
	int m;
	puts("������� ����� ����� ������� N:");
	scanf("%d", &n);
	puts("������� ����� �������� ������� M");
	scanf("%d", &m);
	//create array
	int **a = NULL;
	
	a = (int**) malloc(n*sizeof(int*));
	for(int i = 0; i < n; i++)
	{
		*(a+i) = (int*) malloc(m*sizeof(int));
	}
	// input array
	for(int i = 0; i < n; i++)
	{
		printf("������� ������ ����� %d\n\n", i+1);
		for(int j = 0; j < m; j++)
		{
			scanf("%d", (*(a+i)+j));
		}
	}

	// print
	printAr(a, n,m);


	printf("\n����� �� ������������� ��������� �����: %d\n", f(a,n,m));

	// destroy array
	for(int i = 0; i < n; i++)
	{
		free(*(a+i));
	}
	free(a);

	getch();
}

void printAr(int **a, int n, int m)
{
	puts("������ �������");
	for(int i = 0; i < n; i++)
	{
		printf("\n\n");
		for(int j = 0; j < m; j++)
		{
			printf(" %d   ", *(*(a+i)+j));
		}
	}
	printf("\n\n");
}

int f(int **a, int n, int m)
{
	puts("������ ��������");
	int row_sum= 0;
	int result = 0;
	for(int i = 0; i < n; i++)
	{
		row_sum = 0;
		for(int j = 0; j < m; j++)
		{
			if((*(*(a+i)+j)) < 0) 
			{
				row_sum = 0;
				break;
			} 
			else
			{
				row_sum += (*(*(a+i)+j));
			
			}


		}
		result += row_sum;
	}

	return result;
}