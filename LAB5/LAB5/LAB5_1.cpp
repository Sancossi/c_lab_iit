/*�������� ���������, ���������� ���������������� �������, �������� ���������������� ���� ������. 
��������� �������� ������ � ���� �������, ���� ��������� ������� ������������ � ������� main(). 
������� ������� N � M, �������� ��������� ������� �������� � ����������. 
��������� � ��������� ������� ����������� ������ ����� ��������� ���������, ��������� ������ ����������� �������� new. 
������������� ������� ��������� � ������, ���� �������� ������ �� ��������� ��������� ������������ ������.

4.	����� ��������� ������ �(N, M). � ������� ����� ����� ��������� ������� ��������� � ��������� �� ��� �������� ���� ���������

������� ��������� ��� ������� �� �������� ������ ���� �� ������� �������, � ��������, ��������������, �� ������ ������� � ������ �������.
�.�. M=N
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
	puts("������� ����������� ����� ������� N:");
	scanf("%d", &n);

	puts("������� ����������� ������� ������� M:");
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
		printf("������� ������ %d\n", i+1);
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
	printf("\n����� �������\n");
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