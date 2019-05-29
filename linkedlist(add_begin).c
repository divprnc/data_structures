// WAP to add node at the beginning of the linked list
#include <stdio.h>
#include <malloc.h>

void add(int);
void display();

typedef struct Test
{
	int num;
	struct Test *link; // self referential structure
}T;
T *start; // head node

void main()
{
	system("CLS");
	add(10);
	add(30);
	add(20);
	add(40);
	display();
}

void add(int n)
{
	T *temp;
	temp = (T *) malloc (sizeof(T));
	if (start == NULL)
	{
		start = temp;
		temp -> link = NULL;
	}
	else
	{
		temp -> link = start;
		start = temp;
	}
	temp -> num = n;
	temp = NULL;
	free(temp);
}

void display()
{
	T *disp;
	disp = start;
	while (disp != NULL)
	{
		printf("%d ", disp -> num);
		disp = disp -> link;
	}
	free(disp);
}
