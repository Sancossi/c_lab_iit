

/* ЗАДАНИЕ: Создать программу (выполнив функциональное разбиение) реализующую следующие функции работы с бинарным файлом. Предусмотреть создание меню со следующими пунктами:
1 – СОЗДАНИЕ НОВОГО ФАЙЛА  
2– ПРОСМОТР ФАЙЛА 
3 – КОРРЕКТИРОВКА ЗАПИСЕЙ ФАЙЛА (изменение, добавление новой записи, удаление записи)
4 – ВЫПОЛНЕНИЕ ЗАДАЧИ 
5 – ВЫХОД


4.	Создать файл, содержащий сведения  о сотрудниках фирмы. 
Запись включает: 
Ф.И.О ; 
табельный номер; 
количество проработанных часов за месяц; 
почасовой тариф для данного сотрудника. 

Рабочее время свыше 144 часов считается сверхурочным и оплачивается в двойном размере. 

ВЫВЕСТИ РАЗМЕР ЗАРАБОТНОЙ ПЛАТЫ КАЖДОГО СОТРУДНИКА ФИРМЫ ЗА ВЫЧЕТОМ ПОДОХОДНОГО НАЛОГА, КОТОРЫЙ СОСТАВЛЯЕТ 10% ОТ СУММЫ ЗАРАБОТНОЙ ПЛАТЫ (сортировать по убыванию заработной платы).
*/

#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <io.h>

#define BASEFILE "base.bin"
#define TEMPFILE "temp.bin"

void editFile(void);
int flag(void);
void viewFile(void);
void createFile(void);

FILE *baseFile, *tempFile;
char fullnameToFind[20], fullnameToDel[20];
int p;


struct employee
{
	char fullname[20];// фио
	char prsNumber[2];// персональный номер
	int workingh; // число проработанных часов в месяц
	double hourlyrate; // тариф
};

struct employee tempEmployee;

void main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choise;
	for(;;) // 
	{
		puts("\n\t\tМеню:");
		puts("1 - Создание нового файла");
		puts("2 - Просмотр файла");
		puts("3 - Корректировка записей файла");
		puts("4 - Выполнение задачи");
		puts("5 - Выход");
		printf("Выберите действие: ");
		fflush(stdin);
		scanf("%d", &choise);

		switch(choise)
		{
		case 1:	createFile(); break;
		case 2: viewFile(); break;
		case 3:	editFile(); break;
		case 4:  break;
		case 5: exit(0); break;
		default: puts("Такого пункта меню не существует. Попробуйте снова"); break;
		}
	}



	getch();
}

void createEmployee(void)
{
	printf("\nВведите ФИО: "); 
	scanf("%s", &tempEmployee.fullname);
	fflush(stdin);
	printf("\nВведите персональный номер: ");
	scanf("%s", &tempEmployee.prsNumber);
	fflush(stdin);
	printf("\nВведите число проработанных часов в месяц: ");
	scanf("%d",&tempEmployee.workingh);
	fflush(stdin);
	printf("\nВведите тариф для работника: ");
	scanf("%lf", &tempEmployee.hourlyrate);
}

void editFile(void)
{
	int choise = 0;
	printf("\n\n");
	puts("МЕНЮ РЕДАКТИРОВАНИЯ ФАЙЛА");
	puts("ВЫБЕРИТЕ КОМАНДУ");
	puts("1 - Добавить запись");
	puts("2 - Изменить запись");
	puts("3 - Удалить запись");
	puts("4 - Отмена");
	printf("\nВыберите пункт: ");
	scanf("%d", &choise);
	fflush(stdin);

	switch(choise)
	{
	case 1:
		if(!(baseFile = fopen(BASEFILE, "a+b")))
		{
			puts("Невозможно открыть файл.");
			return;
		}
		
		do
		{
			fflush(stdin);
			createEmployee();
			fflush(stdin);
			fwrite(&tempEmployee,sizeof(employee), 1, baseFile);
			puts("Продолжить Y / N ?");
		}
		while(flag()!=1);
		fclose(baseFile);
		break;
	case 2:
		if(!(baseFile = fopen( BASEFILE, "r+b")))
		{
			puts("Невозможно открыть файл");
			return;
		}
		printf("Введите фамилию для изменения: ");
		fflush(stdin);
		gets(fullnameToFind);
		fread(&tempEmployee, sizeof(employee),1, baseFile);
		while(!feof(baseFile))
		{
			if(strcmp(tempEmployee.fullname,fullnameToFind)==0)
			{
				printf("\n%s, %s, %d, %lf\n", tempEmployee.fullname, tempEmployee.prsNumber,tempEmployee.workingh, tempEmployee.hourlyrate);
				printf("Изменить(Y/N)?");
				if(flag() != 1)
				{
					fflush(stdin);
					createEmployee();
					fflush(stdin);
					p = sizeof(employee);
					fseek(baseFile, -p,1);
					fwrite(&tempEmployee, sizeof(employee),1,baseFile);
					break;
				}
			}
			fread(&tempEmployee,sizeof(employee), 1, baseFile);
		}
		fclose(baseFile);
		break;
	case 3:
		if(!(baseFile = fopen(BASEFILE, "r+b")))
		{
			puts("Невозможно открыть файл");
			return;
		}
		if(!(tempFile = fopen(TEMPFILE, "w+b")))
		{
			puts("Невозможно открыть файл");
			return;
		}
		printf("Введите имя для удаления: ");
		fflush(stdin);
		gets(fullnameToDel);
		fread(&tempEmployee, sizeof(employee), 1, baseFile);
		while(!feof(baseFile))
		{
			if(strcmp(tempEmployee.fullname, fullnameToDel))
			{
				fwrite(&tempEmployee, sizeof(employee), 1, tempFile);
				fread(&tempEmployee, sizeof(employee), 1, baseFile);
			}
			else
			{
				fread(&tempEmployee, sizeof(employee), 1, baseFile);
			}
		}
		fclose(baseFile);
		remove(BASEFILE);
		fclose(tempFile);
		rename(TEMPFILE, BASEFILE);
		if(!(baseFile= fopen(BASEFILE, "r+w")))
		{
			puts("Невозможно открыть вновь созданный файл");
			return;
		}
		while(fread(&tempEmployee, sizeof(employee), 1, baseFile))
		{
			if(feof(baseFile)) break;
			printf("\n%s, %s, %d, %lf\n", tempEmployee.fullname, tempEmployee.prsNumber,tempEmployee.workingh, tempEmployee.hourlyrate);
		}
		fclose(baseFile);
		break;
	case 4:
		return;
	default: puts("Такого пункта не существует. Вы будете возвращены обратно в меню");

	}
}

void viewFile(void)
{
	if(!(baseFile = fopen(BASEFILE, "r+b")))
	{
		puts("Невозможно открыть файл");
		return;
	}
	while(fread(&tempEmployee, sizeof(employee), 1, baseFile))
	{
		if(feof(baseFile)) break;
		printf("\n%s, %s, %d, %lf\n", tempEmployee.fullname, tempEmployee.prsNumber,tempEmployee.workingh, tempEmployee.hourlyrate);
	}
	fclose(baseFile);
}

int flag(void)
{
	char flag1;
	int flag2=1;
	scanf("%c",&flag1);
	fflush(stdin);
	if (flag1!='N' && flag1!='n') {
		flag2=0;
	}
	else flag2=1;
	return flag2;
}

void createFile(void)
{
	if(!(baseFile = fopen(BASEFILE,"w+b")))
	{
		puts("Невозможно открыть файл");
		return;
	}
	do
	{
		fflush(stdin);
		createEmployee();
		fflush(stdin);
		printf("Продолжить ввод(Y/N)?: ");
	}while(flag()!= 1);
	fclose(baseFile);
}