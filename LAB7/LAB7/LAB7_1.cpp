/*
Составить программу, реализующую функции указанного ниже меню. Выполнить функциональное разбиение программного кода.

Меню программы:
1 – Сформировать с клавиатуры строку  и записать в файл (строка может содержать пробелы);
2 – Считать строку из файла и распечатать;
3 – Зашифровать строку и записать в файл;
4 – Расшифровать строку и записать в файл;
5 – Выход. 

После каждой гласной буквы вставляется буква "л".
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
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
		
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
    FILE *mf = NULL; // создали файл
    mf = fopen(filename, "r"); // открыли для чтения

    if(mf==NULL) // проверили все ли нормально
    {
        puts("Error open file");
    }
    else
    {
        puts("Файл успешно открыт");
    }

    s = fgets(s, 255, mf); // получили 255 символов
    fclose(mf); // закрыли файл

    return s; 
}

int menu()
{
	int choise;

	choise = 0;
	puts("Меню программы:");
	puts("1 – Сформировать с клавиатуры строку  и записать в файл");
	puts("2 – Считать строку из файла и распечатать");
	puts("3 – Зашифровать строку и записать в файл");
	puts("4 – Расшифровать строку и записать в файл");
	puts("5 – Выход");
	printf("Выберите пункт меню: ");
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
		puts("Указан не правильный пункт меню. Попробуйте снова");
		break;
	}

}

void writeFile(char *s)
{
	puts("Запись в файл");

	FILE *mf;
	puts("Открытие файла");
	mf=fopen(FILENAME, "a+");
	if(mf == NULL)
	{
		puts("Ошибка открытия файла");
	}
	else
	{
		puts("Открытие файла выполнено");
	}

	fprintf(mf, s);
	puts("Запись в файл выполнена");
	fclose(mf);
	puts("Файл закрыт");
}

/*	
* Функция чтения из файла(обьявлен в глобальных переменных) в буффер. 
* динамически выделяет память под содержимое файла
*/
char* readFile(char* buf, int* filesize, int* bufsize)
{
	FILE *mf = NULL;

	mf = fopen(FILENAME, "r");

	if(mf == NULL)
	{
		puts("Ошибка чтения файла");
	}
	else 
	{
		puts("Файл для чтения открыт");
	}

	*filesize = _filelength(_fileno(mf));// читаем размер файла
	printf("Размер файла: %d\n", *filesize);

	buf = (char*) realloc(buf, ((*filesize)*sizeof(char))); // перераспределяем память в буффере строки

	if(buf == NULL)
	{
		puts("Ошибка перераспределения памяти");
	}
	else
	{
		puts("Перераспределение памяти произоло успешно");
	}

	*bufsize = fread(buf, sizeof(char), sizeof(char)*(*filesize), mf); // считали весь файл в буффер
	if((*bufsize) == NULL)
	{
		puts("Ошибка чтения файла");
	}
	else
	{
		puts("Файл успешно скопирован в буфер");
	}


	fclose(mf);
	return buf;
}

/*
* Выводим содержимое буффера в консоль
*/
void printBuf(char* s)
{
	puts("Содержимое буффера:");

    register char c;
    while((c = *s) != '\0')
    {
        printf("%c",c);
        s++;
    }
}

char* codeBuf(char* buf, int* bufsize)
{
	// считаем колличесво вхождений в массив нужного символа, для того чтобы знать на сколько увеличить буффер
	int count = 0;
	char*result = (char*) malloc(sizeof(char) *(*bufsize)*2);
	for(int i = 0; i < (*bufsize);++i)
	{
		if(isVowel(*(buf+i)))
		{
		

			count++;
		}
	}
	
	printf("\nКолличество вхождений %d\n %s", count, result);
	return result;
	/*	// расширяем буффер на необходимый размер 
	buf = (char*) realloc(buf, (((*bufsize)+count)*sizeof(char)));
	if(buf != NULL)
	{
		puts("Память перераспределена");
	}
	else
	{
		puts("Ошибка перераспределения памяти");
	}
*/
	// вставляем необходимые символы
	
	
}

// проверка является ли символ 
int isVowel(char ch)
{

	switch(ch)
	{
	case 'а':
	case 'о':
	case 'э':
	case 'и':
	case 'у':
	case 'ы':
	case 'е':
	case 'ё':
	case 'ю':
	case 'я':
		return 1;
		break;
	}

	return 0;
}
// удаление символа
char* delc(char* s, int at)
{
    char* start =s;
	s += (at -1);
    while((*s = *(s+1)) != '\0') s++;
	*s = '\0';
    return start;
}
// вставка символа
char* putc(char* s, char c, int at)
{
	char* start = s;
	char* p;
	s += at -1;
	
	p = s;
	printf("%d:%c\n", p, *p);
	while(*p)
	{
			
		p++;// уходим в конец строки
	}
	printf("%d:%c\n", p, *p);
	*(p+1) = '\0'; // добавляем после конца строки еще один символ

	for( ; p != s; --p) p[1] = p[0]; // идем в обртном направлении смещая символы
	*(s+1) = c; // ставим символ 
	return start; // возвращаем указатель на начало строки
}