/*
Написать программу по созданию, просмотру, добавлению и решению поставленной задачи для двунаправленного линейного списка.
Упорядочить элементы списка случайных целых чисел в порядке возрастания.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#define LISTSIZE 10

struct list
{
	int item;
	struct list *prev;
	struct list *next;
};
struct list * init(int); // создание списка
struct list *addEl(list *, int); // добавление элемента
struct list * deleteEl(list*);
struct list* deletehead(list*);
void printlist(list*);
struct list *swap(struct list*, struct list*,struct list*);
struct list* sort(struct list*);

void main()
{
	
	
	srand(time(NULL));
	int r = 2 + rand() % 7;

	struct list *begin = init(0);
	struct list *p = begin;
	struct list *t = begin;
	
	for(int i = LISTSIZE; i>=0; i--)
	{
		r = 2 + rand() % 7;
		t = addEl(t,r);
	}

	printlist(begin);
	puts("-");
	begin = sort(begin);
	printlist(begin);
	//освобождение памяти
	while(p != NULL){
		t=p;

		p = p->next;
		free(t);
	}
	free(p);
	getch();
}

struct list * init(int a)
{
	struct list *buf;
	buf = (struct list*)malloc(sizeof(struct list));
	buf->item = a;
	buf->next = NULL;
	buf->prev = NULL;
	return (buf);
}

struct list *addEl(list *lst, int a)
{
	struct list *tmp, *p;
	tmp = (struct list*)malloc(sizeof(list));
	p = lst->next; // сохраняем указатель на предыдущий узел
	lst->next= tmp; // добавляем узел
	tmp->item = a; // записываем данные
	tmp->next=p; // созданный узел указывает на след узел
	tmp->prev=lst; // созданный узел указывает на прерыдущий узел
	if(p!=NULL)
		p->prev = tmp;
	return(tmp);

}

struct list * deleteEl(list* lst)
{
	struct list *prev, *next;
	prev = lst->prev;
	next = lst->next;
	if(prev != NULL)
	{
		prev->next = lst->next; // переставляем указатели
	}
	if(next!=NULL)
	{
		next->prev = lst->prev;
	}
	free(lst);
	return(prev);
}

struct list* deletehead(list *root)
{
	puts("delhead");
	struct list * tmp;
	tmp = root ->next;
	tmp->prev=NULL;

	free(root);
	return(tmp);
}

void printlist(list *lst)
{
	struct list *p;
	p = lst;

	do{
		printf("%d\n", p->item);
		p = p->next;
	}while(p != NULL);
}
/*
struct list *swap(struct list *lst1, struct list *lst2,struct list *head)
{
	puts("swap");
	struct list *prev1, *prev2, *next1, *next2;
	prev1 = lst1->prev;
	prev2 = lst2->prev;
	next1 = lst1->next;
	next2 = lst2->next;

	if(lst2 == next1) { // обмениваются соседние узлы
		lst2->next = lst1;
		lst2->prev = prev1;
		lst1->next = next2;
		lst1->prev = lst2;
		next2->prev = lst1;
		if(lst1!= head)
			prev1->next = lst2;
	} 
	else 
		if(lst1 == next2) 
		{ // обмениваются соседние узлы
			lst1->next = lst2;
			lst1->prev = prev2;
			lst2->next = next1;
			lst2->prev = lst1;
			next1->prev = lst2;
			if(lst2!= head)
				prev2->next = lst1;
		} 
		else 
		{ // обмениваются отстоящие узлы
			if(lst1 != head)
				prev1->next = lst2;
			lst2->next = next1;
			if(lst2 != head)
				prev2->next = lst1;
			lst1->next = next2;
			lst2->prev = prev1;
			if(next2 != NULL)
				next2->prev = lst1;
			lst1->prev = prev2;
			if(next1 != NULL)
				next1->prev = lst2;
		}
		if(lst1 == head)
			return(lst2);
		if(lst2 == head)
			return(lst1);
		return(head);
}
*/
struct list* sort(struct list* head)
{

	struct list *cur = head;
	struct list *begin = head;
	struct list *next = NULL;

	while(cur)
	{
		next = cur->next;

		while(next)
		{
			if(next->item<cur->item)
			{
				int tmp = next->item;
				next->item = cur->item;
				cur->item=tmp;
			}
			next=next->next;
		}
		cur = cur->next;
	}
	return(head);

}