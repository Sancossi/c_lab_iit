#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <Windows.h>
#include <string.h>
struct bin_tree
{
	int data;
	struct bin_tree * right, * left;
};
typedef struct bin_tree node;


void GoToXY (short x, short y)
{
    HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x, y};
    SetConsoleCursorPosition(StdOut, coord);
}

void insert(node ** tree, int val)
{
	node * temp = NULL;
	// если дерева нет то создаем
	if(!(*tree))
	{
		temp = (node *) malloc(sizeof(node));
		temp -> left = temp -> right = NULL;
		temp -> data = val;
		* tree = temp;
	}
	// если вставляемое значение меньше чем значение текущего дерево уходим на лево
	if(val < (* tree) -> data)
	{
		insert(&(* tree) -> left, val);
	}
	// если вставляемое значение больше чем значение текущего дерево уходим на право
	else if(val > (* tree) -> data)
	{
		insert(&(* tree) -> right, val);
	}
}

void deltree(node * tree)
{
	// если значение есть то то получаем правую левую ссылку и удаляем текущее.
	if(tree)
	{
		deltree(tree -> left);
		deltree(tree -> right);
		free(tree);
	}
}

node * search(node ** tree, int val)
{
	// если дерева нет - то не возвращаем ничего
	if(!(* tree))
	{
		return NULL;
	}
	// если значение для поиска меньше значения текущего то идем на лево
	if(val < (* tree) -> data)
	{
		search(&((* tree)-> left), val);
	}
	// если значение для поиска больше значения текущего то идем на право
	else if(val > (* tree) -> data)
	{
		search(&((* tree) -> right), val);
	}
	// если значение равно искомому то возвращаем ссылку на значение
	else if(val ==(* tree) -> data)
	{
		return * tree;
	}
}


void print (node * root, short x, short y, short a, char c)
{
    if (root) // если дерево есть 
    {
        if (a>0 && c!='k') // если мы использовали ключ - корень или ноль т.е. это первый элемент
        {
            if (c=='l') // если мы использовали ключ - правый 
                x-=10; // то смещаем влево на 10
            else // иначе
                x+=10;
        }
        else 
            if (c!='k')
                if (c=='l')
                    x-=4;
                else
                    x+=4;
        
        GoToXY (x,y+=2); // смещаем курсор в нужную точку
 
        a--;
 
        printf ("%5d", root->data);
        print (root->left,x,y,a,'l'); // запускаем эту функцию с новыми полями для левого листа
        print (root->right,x,y,a,'r'); // запускаем эту фунецию с новыми полями для правого листа
    }
}
void print_tree(node * tree, int l)
{
	if(tree)
	{
		print_tree(tree -> left, l+5);
		for(int i = 0; i < l; i++)
		{
			printf(" ");

		}
		printf("%d\n", tree -> data);
		print_tree(tree -> right, l+5);
	}
}

node * del (node * t, int val)
{
	node * p, *v;
	if(!t)
	{
		puts("Error: tree is not created!");
	} else
		if(val < t -> data)
		{
			t -> left = del(t -> left, val);
		} else if(val > t -> data)
		{
			t -> right = del(t -> right, val);
		} else
		{
			p = t;
			if(!t -> right) t = t -> left;
			else if(!t -> left) t = t -> right;
			else
			{
				if(v -> right)
				{
					while(v -> right -> right) v = v -> right;
					t -> data = v -> right -> data;
					p = v -> right;
					v -> right = v -> right ->left;
				} 
				else 
				{
					t -> data = v -> data;
					p = v;
					t -> left = t -> left -> left;
				}
			}
			free(p);
		}
	
	return t;
}

int getmaxDepth(node * tree, int depht)
{
	if(tree == NULL)
	{
		return depht;
	}
	return max(getmaxDepth(tree->left, depht+1), getmaxDepth(tree->right,depht+1));
}

void main()
{
    
    int n = 0, x = 0, coise = 100;
	node * root = NULL;
	for(;coise!=0;)
	{
		system("cls");
		printf("\n1-insert\n2-delete\n3-print\n4-task\n9-create\n0-Exit\n");
		scanf("%d",&coise);
		switch(coise)
		{
		case 1:
			puts("Insert element: ");
			scanf("%d", &x);
			insert(&root, x);
			system("cls");
			break;
		case 2:
			puts("Delete element: ");
			scanf("%d", &x);
			root = del(root,x);
			system("cls");
			break;
		case 3:
			system("cls");
			print (root,40,5,2,'k');
			printf ("\n\n\n\n\n\n\n\n\n\n");
			system("pause");
			break;
		case 4:
			printf("maxdepth:%d",getmaxDepth(root, 0));
			system("pause");
			break;
		case 9:
			if(root == NULL)
			{
				puts("Insert tree element count: ");
				scanf("%d", &n);
    
    
				for(int i=0;i<n;i++)
				{
					puts("Insert element: ");
					scanf("%d", &x);
					insert(&root, x); 
				}
			}
			else 
			{
				puts("The tree has already been created");
			}
			break;
		case 0:
			puts("App was close");
			break;
		default: 
			puts("Invalid input");
		}
	}
   
  
   
	

	deltree(root);

	system("pause");
	
}