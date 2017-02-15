#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#define SIZE 10


struct Node
{
	int item;
	Node *next;
};
struct Stack
{
	Node *begin;
};

Stack *createStack()
{
	Stack *s = new Stack;
	s ->begin = NULL;
	return s;
}

int empty(Stack *s)
{
	if(s->begin == NULL)
	{
		return 1;
	}
	return 0;
}

void push(Stack *s, int item)
{
	
	printf("push: %d\n",item);
	Node *buf = new Node;
	buf->item = item;
	buf->next = NULL;

	if(empty(s))
	{
		s -> begin = buf;
		return;
	}

	
	Node *n1 = s->begin;
	Node *n2 = s->begin->next;

	while(n2 != NULL)
	{
		n1 = n1->next;
        n2 = n2->next;
	}

	n1 ->next = buf;
}

void pop(Stack *s)
{
	puts("pop");
	if(s->begin == NULL)
	{
		puts("---");
		return;
	}

	Node *buf = s->begin;
	s->begin = s->begin->next;
	delete buf;
}

int top(Stack *s)
{
	return s ->begin->item;
}

void print(Stack *s)
{
	Node *buf = s->begin;
	while(buf!=NULL)
	{
		printf("%d\n",buf->item);
		buf = buf->next;
	}
	printf("\n");
}

void clear_all(Stack *s)
{
	Node *buf = s->begin;
	while(s->begin != NULL)
	{
		pop(s);
	}
}

void swap(Stack *s)
{
	Node *begin = s->begin;
	Node *n1 = s->begin;//end
	Node *n2 = s->begin->next;
	Node *n3 = s->begin;// end -1

	while(n2  != NULL)
	{
		n3 = n1;
		n1 = n1->next;
		n2 = n2->next;
	}

	n1 ->next = s->begin->next;
	s->begin = n1;

	n3->next = begin;
	begin ->next = NULL;
	
}
void main()
{
	srand(time(NULL));
	Stack *s = createStack();
	int r = 0;
	for(int i = 0; i < SIZE; i++)
	{
		r = 2 + rand() % 7;
		push(s,r);
	}
	print(s);
	swap(s);
	print(s);
	clear_all(s);
	delete s;
	getch();
}