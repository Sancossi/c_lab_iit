/*
Для решения задачи необходимо составить три функции: ввод, выполнение задание, печать. 
*/

/*

Написать пользовательскую функцию, решающую указанную ниже задачу. 
Массивы А и В динамические, выделение памяти выполнить функциями calloc() или malloc(), обращение к элементам массива только через указатель. 
Предусмотреть реакцию программы на ситуации, при которых задача не имеет решения.
*/

/*
Заданы два массива А(M) и В(M). 
В каждом из массивов найти наибольшее значение и вычесть его из всех элементов массивов. 
На печать вывести исходные и преобразованные массивы.
*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>

void inputArray(int*, int);// Ввод массива
void modifyArray(int*,int); // Вычитание из массива максимального числа найденного в нем
void printArray(int*,int); // Вывод массива на печать

void main()
{

	/**/
	setlocale(LC_CTYPE, "Russian");
	
	int lenght;

	puts("Введите длинну массива A:");

	scanf("%d", &lenght);
	int* a = (int*) malloc(sizeof(int) * lenght);
	int* testarray = (int*) malloc(sizeof(int) * lenght);
	inputArray(a, lenght);
	printArray(a, lenght);
	modifyArray(a, lenght);
	printArray(a, lenght);
	puts("Введите длинну массива B:");

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
		puts("Ввод элементов массива");
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
	
		
		puts("Введите элементы массива");

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
		puts("Модификация");
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