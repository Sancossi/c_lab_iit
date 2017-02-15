/*
��������� ���������, ����������� ������� ���������� ���� ����. ��������� �������������� ��������� ������������ ����.

���� ���������:
1 � ������������ � ���������� ������  � �������� � ���� (������ ����� ��������� �������);
2 � ������� ������ �� ����� � �����������;
3 � ����������� ������ � �������� � ����;
4 � ������������ ������ � �������� � ����;
5 � �����. 

����� ������ ������� ����� ����������� ����� "�".
*/

#include <stdio.h>
#include <locale.h>  
#include <conio.h> 
#include <io.h>
#include <Windows.h>

#define FILENAME "FILE.TXT"

int menu();
void writeFile(char*);
char* readFile(char*,  int*, int*);
char* codeBuf(char*, int*);
void encodeBuf(char*, int*);
void printBuf(char*);
int isVowel(char);
char* delc(char*, int);
char* putc(char*, char, int);
char* readf(char*, char*);

void main()
{
	setlocale(LC_CTYPE, "Russian");
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
    SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
		
	int filesize = 0;
	int bufsize = 0;
	
	char *s = (char*) malloc(sizeof(char)*255);
	s = readf(s, FILENAME);
	printf("%s", s);
	s = putc(s, 'k', 0);
	printf("%s", s);
	free(s);
	getch();
}

char* readf(char* s, char* filename)
{
    FILE *mf = NULL; // ������� ����
    mf = fopen(filename, "r"); // ������� ��� ������

    if(mf==NULL) // ��������� ��� �� ���������
    {
        puts("Error open file");
    }
    else
    {
        puts("���� ������� ������");
    }

    s = fgets(s, 255, mf); // �������� 255 ��������
    fclose(mf); // ������� ����

    return s; 
}

int menu()
{
	int choise;

	choise = 0;
	puts("���� ���������:");
	puts("1 � ������������ � ���������� ������  � �������� � ����");
	puts("2 � ������� ������ �� ����� � �����������");
	puts("3 � ����������� ������ � �������� � ����");
	puts("4 � ������������ ������ � �������� � ����");
	puts("5 � �����");
	printf("�������� ����� ����: ");
	scanf("%d", &choise);
	switch(choise)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		return 5;
		break;
	default:
		puts("������ �� ���������� ����� ����. ���������� �����");
		break;
	}

}

void writeFile(char *s)
{
	puts("������ � ����");

	FILE *mf;
	puts("�������� �����");
	mf=fopen(FILENAME, "a+");
	if(mf == NULL)
	{
		puts("������ �������� �����");
	}
	else
	{
		puts("�������� ����� ���������");
	}

	fprintf(mf, s);
	puts("������ � ���� ���������");
	fclose(mf);
	puts("���� ������");
}

/*	
* ������� ������ �� �����(�������� � ���������� ����������) � ������. 
* ����������� �������� ������ ��� ���������� �����
*/
char* readFile(char* buf, int* filesize, int* bufsize)
{
	FILE *mf = NULL;

	mf = fopen(FILENAME, "r");

	if(mf == NULL)
	{
		puts("������ ������ �����");
	}
	else 
	{
		puts("���� ��� ������ ������");
	}

	*filesize = _filelength(_fileno(mf));// ������ ������ �����
	printf("������ �����: %d\n", *filesize);

	buf = (char*) realloc(buf, ((*filesize)*sizeof(char))); // ���������������� ������ � ������� ������

	if(buf == NULL)
	{
		puts("������ ����������������� ������");
	}
	else
	{
		puts("����������������� ������ �������� �������");
	}

	*bufsize = fread(buf, sizeof(char), sizeof(char)*(*filesize), mf); // ������� ���� ���� � ������
	if((*bufsize) == NULL)
	{
		puts("������ ������ �����");
	}
	else
	{
		puts("���� ������� ���������� � �����");
	}


	fclose(mf);
	return buf;
}

/*
* ������� ���������� ������� � �������
*/
void printBuf(char* s)
{
	puts("���������� �������:");

    register char c;
    while((c = *s) != '\0')
    {
        printf("%c",c);
        s++;
    }
}

char* codeBuf(char* buf, int* bufsize)
{
	// ������� ���������� ��������� � ������ ������� �������, ��� ���� ����� ����� �� ������� ��������� ������
	int count = 0;
	char*result = (char*) malloc(sizeof(char) *(*bufsize)*2);
	for(int i = 0; i < (*bufsize);++i)
	{
		if(isVowel(*(buf+i)))
		{
		

			count++;
		}
	}
	
	printf("\n����������� ��������� %d\n %s", count, result);
	return result;
	/*	// ��������� ������ �� ����������� ������ 
	buf = (char*) realloc(buf, (((*bufsize)+count)*sizeof(char)));
	if(buf != NULL)
	{
		puts("������ ����������������");
	}
	else
	{
		puts("������ ����������������� ������");
	}
*/
	// ��������� ����������� �������
	
	
}

// �������� �������� �� ������ 
int isVowel(char ch)
{

	switch(ch)
	{
	case '�':
	case '�':
	case '�':
	case '�':
	case '�':
	case '�':
	case '�':
	case '�':
	case '�':
	case '�':
		return 1;
		break;
	}

	return 0;
}
// �������� �������
char* delc(char* s, int at)
{
    char* start =s;
	s += (at -1);
    while((*s = *(s+1)) != '\0') s++;
	*s = '\0';
    return start;
}
// ������� �������
char* putc(char* s, char c, int at)
{
	char* start = s;
	char* p;
	s += at -1;
	
	p = s;
	printf("%d:%c\n", p, *p);
	while(*p)
	{
			
		p++;// ������ � ����� ������
	}
	printf("%d:%c\n", p, *p);
	*(p+1) = '\0'; // ��������� ����� ����� ������ ��� ���� ������

	for( ; p != s; --p) p[1] = p[0]; // ���� � ������� ����������� ������ �������
	*(s+1) = c; // ������ ������ 
	return start; // ���������� ��������� �� ������ ������
}