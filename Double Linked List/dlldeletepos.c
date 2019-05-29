// WAP to delete node at the position in double linked list
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void add_end(int);
void display();
void delete_pos();

typedef struct Test
{
	int num;
	struct Test *prev;
	struct Test *next;
}T;
T *start;

void main()
{
	system("CLS");
	add_end(10);
	add_end(20);
	add_end(30);
	add_end(40);
	display();
	delete_pos();
	display();
}

void add_end(int n)
{
	T *temp, *disp;
	temp = (T *) malloc (sizeof(T));
	temp -> num = n;
	if (start == NULL)
	{
		start = temp;
		temp -> prev = NULL;
		temp -> next = NULL;
	}
	else
	{
		disp = start;
		while (disp -> next != NULL)
		{
			disp = disp -> next;
		}
		disp -> next = temp;
		temp -> prev = disp;
		temp -> next = NULL;
	}
	disp = NULL;
	temp = NULL;
	free(disp);
	free(temp);
}

void delete_pos()
{
	T *disp;
	int pos, i;
	
	printf("\nEnter the position you want to delete : ");
	scanf("%d", &pos);
	
	if (pos <= 0)
	{
		printf("\nCannot delete at this position");
		getch();
		exit(0);
	}
	else
	{
		disp = start;
		for (i = 1; i <= (pos - 1); i++)
		{
			disp = disp -> next;
		}	
		disp -> prev -> next = disp -> next;
		disp -> next -> prev = disp -> prev;
	}
	free(disp);
}

void display()
{
	T *last;
	last = start;
	while (last != NULL)
	{
		printf("%d ", last -> num);
		last = last -> next;
	}
	free(last);
}
