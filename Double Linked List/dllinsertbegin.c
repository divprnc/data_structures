// WAP to insert node at the beginning in double linked list
#include <stdio.h>
#include <malloc.h>

void add_begin(int);
void display();

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
	add_begin(10);
	add_begin(20);
	add_begin(30);
	add_begin(40);
	display();
}

void add_begin(int n)
{
	T *temp;
	temp = (T *) malloc (sizeof(T));
	temp -> num = n;
	
	temp -> prev = NULL;
	temp -> next = start;
	start = temp;
	
	temp = NULL;
	free(temp);
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
