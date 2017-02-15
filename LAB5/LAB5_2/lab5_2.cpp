/*
Написать программу, содержащую пользовательскую функцию, решающую сформулированную ниже задачу. 
Во всех заданиях предусмотреть захват и освобождение динамической памяти (calloc или malloc). 
На печать в виде таблиц вывести исходный двухмерный массив. 
Размеры массива N и M, элементы массива ввести с клавиатуры в функции main(). 
Предусмотреть реакцию программы в случае, если исходные данные не позволяют выполнить поставленную задачу.

4.	Дан целочисленный прямоугольный массив. Определить произведение элементов в тех строках, которые не содержат отрицательных элементов.
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
	puts("Введите число строк массива N:");
	scanf("%d", &n);
	puts("Введите число столбцов массива M");
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
		printf("Введите строку номер %d\n\n", i+1);
		for(int j = 0; j < m; j++)
		{
			scanf("%d", (*(a+i)+j));
		}
	}

	// print
	printAr(a, n,m);


	printf("\nСумма не отрицательных элементов равна: %d\n", f(a,n,m));

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
	puts("Печать массива");
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
	puts("Начало подсчета");
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