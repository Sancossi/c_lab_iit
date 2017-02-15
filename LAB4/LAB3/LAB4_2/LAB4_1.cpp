/*
Написать пользовательскую функцию, решающую указанную ниже задачу. 
Массив создается в динамической области памяти функцией new. 
При обращении к элементам массива воспользоваться взаимосвязью массивов с указателями (косвенная адресация). 
Предусмотреть реакцию программы на ситуации, при которых задача не имеет решения.

В одномерном массиве, состоящем из n вводимых с клавиатуры элементов, вычислить:
*/

/*
Сумму элементов массива, расположенных между первым и последним положительными элементами;
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

	puts("Введите размер массива:");
	
	int lenght;

	scanf("%d", &lenght);
	if(lenght <= 0)
	{
		puts("Неверная длинна массива");
		return;
	}

	int* a = new int[lenght];
	if(a==NULL)
	{
		puts("Ошибка выделения памяти");
		return;
	}

	inputArray(a, lenght);
	printArray(a, lenght);
	printf("\nСумма элементов равна %d\n", getSum(a, lenght));
	delete[]a;
}


void inputArray(int* a, int lenght)
{
	puts("Ввод массива.");
	for(int i=0; i < lenght; i++)
	{
		printf("\nВведите %d элемент массива: ", i);
		scanf("%d", a+i);
	}

}

void printArray(int* a, int lenght)
{
	puts("Вывод массива");
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
		puts("Ошибка. Все элементы отрицательны или равны нулю");
		getch();
		return 0;
	}
	printf("\nПервый положительный элемент найден. Индекс: %d\n", firstElement);
	for(int i = lenght - 1; i > -1; i--)
	{
		if(*(a+i) > 0)
		{
			lastElement = i;
			break;
		}
	}
	printf("\Последний положительный элемент найден. Индекс: %d\n", lastElement);

	for(int i = firstElement; i <= lastElement; i++)
	{
		result += (*(a+i));
	}

	return result;
}