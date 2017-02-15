#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

#define PI 3.1417

double fact(double a);

void main()
{
	setlocale(LC_CTYPE, "Russian");
	
	double x = 0.0;
	double a = 0.0;
	double b = 0.0;
	double h = 0.0;

	double y = 0.0;
	double s = 0.0;
	double mod = 0.0; // fabs(s - y)

	puts("Введите исходные данные\n");
	puts("Начало промежутка a:\n");
	scanf("%lf", &a);
	puts("Конец промежутка b:\n");
	scanf("%lf", &b);
	puts("Шаг h:\n");
	scanf("%lf", &h);
	

	printf(" x\t\t y\t\t s\t\t |s-y|\t\t\n");
	for(double x = a; x <= b; x += h)
	{
		y = cos(x);

		s = 0.0;
		for(double k = 0; k <= x; k++)
		{
			s += cos(k*PI/4)/fact(k)*pow(x,k);
		}

		mod = fabs(s-y);

		printf("%4.4lf\t\t%4.4lf\t\t%4.4lf\t\t%4.4lf\n", x, y, s, mod);
	}

	getch();
}

double fact(double a)
{
	
	double result = 1;
	for(double i = 1; i <= a; i++)
	{
		result *= i;
	}
	return result;
}