/*11  � ������� ���������� ��������� ������� ������� ����, 
���������� �����, ����� �������� �� ��������� 1000 �������� 
(����� ������ ������ �� ������ ��������� 70 ��������).
���� ������ ����� ���������� DAT. 
�������� ���������, �������:
-	������� ����� �� ����� �������;
-	���������� ���������� ���� �a� � ��������� ����� ������.
*/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <process.h>

#define MAX_FILE_SIZE 1000
#define FILE_NAME "FILE.TXT"
void readfile(char *t)
{
	setlocale(LC_CTYPE, "Russian");
	int i = 0; // ������ ������ ���������� �����
	int sp = 0;
	int n = 0; // ����� �������� 

	char *d = "a";

	// ��������� ����
	FILE *f;
	if(!(f = fopen(FILE_NAME, "r+")))
	{
		puts("������ �������� �����");
		return;
	}
	
	// ������ ����� 
	// ������ � ����������� ����
	for(;;)
	{
		char c = fgetc(f);
		if(c == EOF)
		{
			if(feof(f) != 0) break;
		}

		else if(c == '\n') continue; // ���� ����� ������ 
		else if(c == ' ') sp = i;
		t[i] = c;
		printf("%c", t[i++]); 
		
	}
	for(;;)
	{
		if(t[++sp] == *d) n++;
		else if(sp = i) break;
	}
	printf("\n ��� ��������� : %d ��������\n � ��������� ����� %d �������� ", i, n);
	fclose(f);
}
void main()
{
	setlocale(LC_CTYPE, "Russian");
	char *text = new char[MAX_FILE_SIZE];
	readfile(text);
	delete[] text;
	_getch();
}