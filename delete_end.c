// Program to delete node at the end of linked list
#include <stdio.h>
#include <malloc.h>

void add(int);
void display();
void delete_end();
void delete_begin();
void delete_pos();

typedef struct Test
{
	int num;
	struct Test *link; // self referential structure
}T;
T *start; //head node

void main()
{
	system("CLS");
	add(10);
	add(20);
	add(30);
	add(40);
	add(50);
	add(60);
	display();
	delete_pos();
	display();
} 

void add(int n)
{
	T *temp, *disp;
	temp = (T *) malloc (sizeof(T));
	temp -> num = n;
	
	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		disp = start;
		while (disp -> link != NULL)
		{
			disp = disp -> link;
		}
		disp -> link = temp;
	}

	temp -> link = NULL;
	temp = NULL;
	disp = NULL;
	free(disp);
	free(temp);
}

void delete_begin()
{
	T *temp;
	temp = start;
	start = temp -> link;
	temp -> link = NULL;
	free(temp);
}

void delete_pos()
{
	int pos, i;
	printf("\nEnter the position to delete : ");
	scanf("%d", &pos);
	T *temp, *disp;
	temp = start;
	for (i = 1; i < (pos - 1); i++)
	{
		temp = temp -> link;
		disp = temp -> link;
	}
	temp -> link = disp -> link;
	disp -> link = NULL;
	temp = NULL;
	free(temp);
	free(disp);
}

void delete_end()
{
	T *last, *temp;
	temp = start;
	while (temp -> link != NULL)
	{
		last = temp;
		temp = temp -> link;
	}
	last -> link = NULL;
	last = NULL;
	free(last);
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
