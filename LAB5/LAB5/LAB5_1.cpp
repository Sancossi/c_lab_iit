/*Написать программу, содержащую пользовательскую функцию, решающую сформулированную ниже задачу. 
Программа печатает массив в виде таблицы, ввод элементов массива производится в функции main(). 
Размеры массива N и M, значения элементов массива вводятся с клавиатуры. 
Обращение к элементам массива выполняется только через косвенную адресацию, выделение памяти выполняется функцией new. 
Предусмотреть реакцию программы в случае, если исходные данные не позволяют выполнить поставленную задачу.

4.	Задан двумерный массив А(N, M). В массиве найти сумму элементов главной диагонали и разделить на нее значения всех элементов

Главная диагональ идёт начиная от верхнего левого угла до нижнего правого, а побочная, соответственно, из левого нижнего в правый верхний.
т.е. M=N
*/
#include <stdio.h>
#include <conio.h>
#include <locale.h>

void printArray(double**, int, int);
double getSum(double**, int, int);
void modyfyArray(double**, int, int, double);

void main()
{
	double sum; // summ value diagamam
	int n; // array row
	int m; // array collunm
	
	setlocale(LC_CTYPE, "Russian");


	// input size array
	puts("Введите колличество строк массива N:");
	scanf("%d", &n);

	puts("Введите колличество стобцов массива M:");
	scanf("%d", &m);

	double** a; // array


	// create array
	a = new double *[n];
	
	for(int i = 0; i < n; i++)
	{
		*(a+i)= new double [m];
	}
	// input array
	for(int i = 0; i < n; i++)
	{
		printf("Введите строку %d\n", i+1);
		for(int j = 0; j < m; j++)
		{	
			scanf("%lf", ((*(a+i)+j)));
			//*(*(a+i)+j) = (i+1)*10+(j+1);
		}
	}

	// print array

	printArray(a, n, m);	
	
	
	// modufy array
	sum = getSum(a,n,m);

	modyfyArray(a, n, m, sum);

	printArray(a, n, m);
	//delete array

	for(int i = 0; i < n; i++)
	{
		delete[] (*(a+i));
	}
	delete[] a;
	
}


void printArray(double **a, int n, int m)
{
	// *n
	// *m
	printf("\nВывод массива\n");
	for(int i = 0; i < n; i++)
	{
		printf("\n\n");
		for(int j = 0; j < m; j++)
		{
			printf(" %.4lf ", *(*(a+i)+j));
		}

	}
}

double getSum(double **a, int n, int m)
{
	double result = 0;

	for(int i = 0; (i < n)&&(i < m); i++)
	{
		result += *(*(a+i)+i);
	}
	return result;
}

void modyfyArray(double **a, int n, int m, double sum)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			*(*(a+i)+j) /= sum;
		}
	}

}