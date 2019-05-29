// WAP to delete node at the last in double linked list
#include <stdio.h>
#include <malloc.h>

void add_end(int);
void display();
void delete_end();

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
	printf("\n");
	delete_end();
	display();
	printf("\n");
	delete_end();
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

void delete_end()
{
	T *last;
	last = start;
	while (last -> next != NULL)
	{
		last = last -> next;
	}
	last -> prev -> next= NULL;
	free(last);
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
