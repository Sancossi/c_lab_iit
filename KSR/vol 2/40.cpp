/*40
Для хранения данных о ноутбуках описать структуру вида, описанного в Задаче 39.
Написать функцию, которая читает данные о ноутбуках из файла note.txt в структуру приведенного вида. 
Написать функцию, которая записывает содержи¬мое структуры в конец бинарного файла.
Структура бинарного файла: первые два байта — целое число записей в файле; далее записи в формате структуры NOTEBOOK.
Написать программу, в которой на основе разработанных функций осуществляется запись в двоичный файл данных только о тех ноутбуках, цена которых боль¬ше $3500,
отсортированные в порядке возрастания тактовой частоты процессора.
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
	char name[20];//20	наименование модели;
	int price;//5 цена в долларах;
	float weight;//4 масса ноутбука в кг;
	struct dem{//5x4x4
		float width;//5
		float lenght;//4
		float height;//4
	};//габаритные размеры ноутбука в дюймах(ВЫСОТАхДЛИНАхШИРИНА три числа с десятичной точкой(4 символа, включая точку, разделенные 'х');
	dem dement;
	int freq;//4 частота процессора в МГц;
	int ram;//3 максимальный объем ОЗУ в мегабайтах;
	float ich;//4 размер диагонали дисплея в дюймах (число с десятичной точкой из четырех символов, включая точку);
	int gram;//2 размер видеопамяти в мегабайтах ;
	struct res{//5x4
		int width;//5
		int height;//4
	}; // разрешающая способность дисплея в пикселах;
	res resol;
	int dfreq;// 3 частота регенерации дисплея в Гц;
	float hdd;// 6 объем HDD в гигабайтах.
	char x[5];//буфер для разделительных символов "x"
}noot;


noot a[40] ,b[20], c[20];


void func_read()
{
	char h;
	puts("");
	puts("Для чтения нажмите ENTER");
	puts("Для отмены ЛЮБАЯ КЛАВИША");
	
	h = _getch();
	if(h != '\r') 
	{
		return;	
	}
	
	
	FILE *f;
	if(!(f = fopen("note.txt", "r+")))
	{
		puts("Невозможно открыть файл");
		return;
	}
	else 
	{
		puts("Файл успешно открыт");
	}

	while((fgets(a[n].name, 20,f) != NULL)) // 
	{
		fscanf(f, " %d   %f   %f%c%f%c%f   %d   %d   %f   %d   %d%c%d   %d   %f\n", &a[n].price, &a[n].weight, &a[n].dement.width, a[n].x, &a[n].dement.lenght, a[n].x, &a[n].dement.height, &a[n].freq, &a[n].ram, &a[n].ich, &a[n].gram, &a[n].resol.width, a[n].x, &a[n].resol.height, &a[n].dfreq, &a[n].hdd); 
		n++;
	}
	printf("Прочитано %d строк\n",n);
	puts("Закрываем файл");
	fclose(f);
}

void func_sort()
{
	int finecount = 0;//колличество ноутбуков за 3500
	puts("Начинаем поиск");
	for(int i = 0; i < n; i++)
	{
		if(a[i].price>= FINE_PRICE)
		{
			b[finecount] = a[i]; // сохраняем полученный компьютер
			finecount++;//увеличиваем счетчик на 1
		}
	}
	printf("Найдено %d ноутбуков удовлетворяющих условию\n", finecount);
	//сортировка
	c[0] = b[0];
	puts("Начинаем сортировку");
	for(int i = 0; i < finecount; i++)
	{
		for(int k = i; k >= 0; k--)
		{
			if(b[i].freq <= c[k-1].freq)
			{
				c[k] =c[k-1]; // смещаем к концу массива
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
	puts("Сортировка окочена");
	n = finecount;
}

void func_write()
{

	FILE *f;

	if(!(f = fopen(PATH_BIN, "wb")))
	{
		puts("Ошибка открытия бинарного файла");
		return;
	}

	fprintf(f, "%2d", n); // колличество записей после сортировки
	fwrite(c, sizeof(c[0]),n,f);
	puts("Данные записаны в файл");
	fclose(f);
	puts("Файл закрыт");
	
}

void func_print_result()
{
	puts("Проверка:"); 
	int d; 
	noot D[10];	
	FILE *z = fopen(PATH_BIN, "rb"); 
	if(z == NULL)
	{
		puts("Ошибка открытия файла");
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