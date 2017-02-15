

/* �������: ������� ��������� (�������� �������������� ���������) ����������� ��������� ������� ������ � �������� ������. ������������� �������� ���� �� ���������� ��������:
1 � �������� ������ �����  
2� �������� ����� 
3 � ������������� ������� ����� (���������, ���������� ����� ������, �������� ������)
4 � ���������� ������ 
5 � �����


4.	������� ����, ���������� ��������  � ����������� �����. 
������ ��������: 
�.�.� ; 
��������� �����; 
���������� ������������� ����� �� �����; 
��������� ����� ��� ������� ����������. 

������� ����� ����� 144 ����� ��������� ������������ � ������������ � ������� �������. 

������� ������ ���������� ����� ������� ���������� ����� �� ������� ����������� ������, ������� ���������� 10% �� ����� ���������� ����� (����������� �� �������� ���������� �����).
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
	char fullname[20];// ���
	char prsNumber[2];// ������������ �����
	int workingh; // ����� ������������� ����� � �����
	double hourlyrate; // �����
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
		puts("\n\t\t����:");
		puts("1 - �������� ������ �����");
		puts("2 - �������� �����");
		puts("3 - ������������� ������� �����");
		puts("4 - ���������� ������");
		puts("5 - �����");
		printf("�������� ��������: ");
		fflush(stdin);
		scanf("%d", &choise);

		switch(choise)
		{
		case 1:	createFile(); break;
		case 2: viewFile(); break;
		case 3:	editFile(); break;
		case 4:  break;
		case 5: exit(0); break;
		default: puts("������ ������ ���� �� ����������. ���������� �����"); break;
		}
	}



	getch();
}

void createEmployee(void)
{
	printf("\n������� ���: "); 
	scanf("%s", &tempEmployee.fullname);
	fflush(stdin);
	printf("\n������� ������������ �����: ");
	scanf("%s", &tempEmployee.prsNumber);
	fflush(stdin);
	printf("\n������� ����� ������������� ����� � �����: ");
	scanf("%d",&tempEmployee.workingh);
	fflush(stdin);
	printf("\n������� ����� ��� ���������: ");
	scanf("%lf", &tempEmployee.hourlyrate);
}

void editFile(void)
{
	int choise = 0;
	printf("\n\n");
	puts("���� �������������� �����");
	puts("�������� �������");
	puts("1 - �������� ������");
	puts("2 - �������� ������");
	puts("3 - ������� ������");
	puts("4 - ������");
	printf("\n�������� �����: ");
	scanf("%d", &choise);
	fflush(stdin);

	switch(choise)
	{
	case 1:
		if(!(baseFile = fopen(BASEFILE, "a+b")))
		{
			puts("���������� ������� ����.");
			return;
		}
		
		do
		{
			fflush(stdin);
			createEmployee();
			fflush(stdin);
			fwrite(&tempEmployee,sizeof(employee), 1, baseFile);
			puts("���������� Y / N ?");
		}
		while(flag()!=1);
		fclose(baseFile);
		break;
	case 2:
		if(!(baseFile = fopen( BASEFILE, "r+b")))
		{
			puts("���������� ������� ����");
			return;
		}
		printf("������� ������� ��� ���������: ");
		fflush(stdin);
		gets(fullnameToFind);
		fread(&tempEmployee, sizeof(employee),1, baseFile);
		while(!feof(baseFile))
		{
			if(strcmp(tempEmployee.fullname,fullnameToFind)==0)
			{
				printf("\n%s, %s, %d, %lf\n", tempEmployee.fullname, tempEmployee.prsNumber,tempEmployee.workingh, tempEmployee.hourlyrate);
				printf("��������(Y/N)?");
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
			puts("���������� ������� ����");
			return;
		}
		if(!(tempFile = fopen(TEMPFILE, "w+b")))
		{
			puts("���������� ������� ����");
			return;
		}
		printf("������� ��� ��� ��������: ");
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
			puts("���������� ������� ����� ��������� ����");
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
	default: puts("������ ������ �� ����������. �� ������ ���������� ������� � ����");

	}
}

void viewFile(void)
{
	if(!(baseFile = fopen(BASEFILE, "r+b")))
	{
		puts("���������� ������� ����");
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
		puts("���������� ������� ����");
		return;
	}
	do
	{
		fflush(stdin);
		createEmployee();
		fflush(stdin);
		printf("���������� ����(Y/N)?: ");
	}while(flag()!= 1);
	fclose(baseFile);
}