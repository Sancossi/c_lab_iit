#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <math.h>

#define PI 3.1417
double findY(double*);
double findS(int&, double&); 
double fact(double);

void main()
{	
	setlocale(LC_CTYPE, "Russian");
	
	double x,a,b,h,y,s,mod; 
	int n;

	puts("������� �������� ������\n");
	puts("������ ���������� a:\n");
	scanf("%lf", &a);
	puts("����� ���������� b:\n");
	scanf("%lf", &b);
	puts("��� h:\n");
	scanf("%lf", &h);
	puts("������� ������� n: \n");
	scanf("%d", &n);
	
	printf(" x\t\t y\t\t s\t\t |s-y|\t\t\n");
	for(double x = a; x <= b; x += h)
	{
		y = findY(&x);

		s = findS(n,x);
		

		mod = fabs(s-y);

		printf("%4.4lf\t\t%4.4lf\t\t%4.4lf\t\t%4.4lf\n", x, y, s, mod);
	}
	getch();
	return ;
}

double findY(double *x) 
{
	return cos(*x);
}

double findS(int &n, double &x)
{
	double result = 0.0;
	for(int k = 0; k <= n; k++)
	{
		result += cos(k*PI/4)/fact(k)*pow(x,k);
	}
	return result;
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
