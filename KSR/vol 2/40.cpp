/*40
��� �������� ������ � ��������� ������� ��������� ����, ���������� � ������ 39.
�������� �������, ������� ������ ������ � ��������� �� ����� note.txt � ��������� ������������ ����. 
�������� �������, ������� ���������� ���������� ��������� � ����� ��������� �����.
��������� ��������� �����: ������ ��� ����� � ����� ����� ������� � �����; ����� ������ � ������� ��������� NOTEBOOK.
�������� ���������, � ������� �� ������ ������������� ������� �������������� ������ � �������� ���� ������ ������ � ��� ���������, ���� ������� ������� $3500,
��������������� � ������� ����������� �������� ������� ����������.
*/


#include<conio.h>
#include<stdio.h>
#include<locale.h>
#include<malloc.h>
#include<stdlib.h>
#include<process.h>
#include<io.h>

#define PATH "note.txt"
#define PATH_BIN "note.bin"

#define FINE_PRICE 3500

int n = 0;
typedef struct notebook {
	char name[20];//20	������������ ������;
	int price;//5 ���� � ��������;
	float weight;//4 ����� �������� � ��;
	struct dem{//5x4x4
		float width;//5
		float lenght;//4
		float height;//4
	};//���������� ������� �������� � ������(������������������� ��� ����� � ���������� ������(4 �������, ������� �����, ����������� '�');
	dem dement;
	int freq;//4 ������� ���������� � ���;
	int ram;//3 ������������ ����� ��� � ����������;
	float ich;//4 ������ ��������� ������� � ������ (����� � ���������� ������ �� ������� ��������, ������� �����);
	int gram;//2 ������ ����������� � ���������� ;
	struct res{//5x4
		int width;//5
		int height;//4
	}; // ����������� ����������� ������� � ��������;
	res resol;
	int dfreq;// 3 ������� ����������� ������� � ��;
	float hdd;// 6 ����� HDD � ����������.
	char x[5];//����� ��� �������������� �������� "x"
}noot;


noot a[40] ,b[20], c[20];


void func_read()
{
	char h;
	puts("");
	puts("��� ������ ������� ENTER");
	puts("��� ������ ����� �������");
	
	h = _getch();
	if(h != '\r') 
	{
		return;	
	}
	
	
	FILE *f;
	if(!(f = fopen("note.txt", "r+")))
	{
		puts("���������� ������� ����");
		return;
	}
	else 
	{
		puts("���� ������� ������");
	}

	while((fgets(a[n].name, 20,f) != NULL)) // 
	{
		fscanf(f, " %d   %f   %f%c%f%c%f   %d   %d   %f   %d   %d%c%d   %d   %f\n", &a[n].price, &a[n].weight, &a[n].dement.width, a[n].x, &a[n].dement.lenght, a[n].x, &a[n].dement.height, &a[n].freq, &a[n].ram, &a[n].ich, &a[n].gram, &a[n].resol.width, a[n].x, &a[n].resol.height, &a[n].dfreq, &a[n].hdd); 
		n++;
	}
	printf("��������� %d �����\n",n);
	puts("��������� ����");
	fclose(f);
}

void func_sort()
{
	int finecount = 0;//����������� ��������� �� 3500
	puts("�������� �����");
	for(int i = 0; i < n; i++)
	{
		if(a[i].price>= FINE_PRICE)
		{
			b[finecount] = a[i]; // ��������� ���������� ���������
			finecount++;//����������� ������� �� 1
		}
	}
	printf("������� %d ��������� ��������������� �������\n", finecount);
	//����������
	c[0] = b[0];
	puts("�������� ����������");
	for(int i = 0; i < finecount; i++)
	{
		for(int k = i; k >= 0; k--)
		{
			if(b[i].freq <= c[k-1].freq)
			{
				c[k] =c[k-1]; // ������� � ����� �������
				if (k == 1)
				{ 
					c[k - 1] = b[i];
				}
			} 
			else
			{
				 if (b[i].freq > c[k - 1].freq)
				 { 
					 c[k] = b[i];
					 break; 
				 }
			}
		}
	}
	puts("���������� �������");
	n = finecount;
}

void func_write()
{

	FILE *f;

	if(!(f = fopen(PATH_BIN, "wb")))
	{
		puts("������ �������� ��������� �����");
		return;
	}

	fprintf(f, "%2d", n); // ����������� ������� ����� ����������
	fwrite(c, sizeof(c[0]),n,f);
	puts("������ �������� � ����");
	fclose(f);
	puts("���� ������");
	
}

void func_print_result()
{
	puts("��������:"); 
	int d; 
	noot D[10];	
	FILE *z = fopen(PATH_BIN, "rb"); 
	if(z == NULL)
	{
		puts("������ �������� �����");
		return;
	}
	fscanf(z, "%2d", &d);	
	int co = sizeof(D[0]);	
	fread(D, sizeof(D[0]), d, z); 
	for (int i = 0; i<d; i++) {
		printf(" %20s %5d %.1f %.1fx%.1fx%.1f\n %4d %3d %.2f %2d %5dx%d %3d %.4f\n", D[i].name, D[i].price, D[i].weight, D[i].dement.width, D[i].dement.lenght, D[i].dement.height, D[i].freq, D[i].ram, D[i].ich, D[i].gram, D[i].resol.width, D[i].resol.height, D[i].dfreq, D[i].hdd); 
	}
	fclose(z);
}


void main()
{
	setlocale(LC_CTYPE, "Russian");

	func_read();
	func_sort();
	func_write();
	func_print_result();
	_getch();
}