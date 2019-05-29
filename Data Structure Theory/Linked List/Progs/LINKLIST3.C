// program to insert node at the beginning , middle and end of the linked list and display the item of the node
#include <stdio.h>
#include<conio.h>
#include <malloc.h>
#include <stdlib.h>
#define clrscr() ("CLS")
void add_begin(int);
void add_middle(int , int);
void add_end(int);
void display();
struct employee
{
	int info;
	struct employee *link; // self referential structure
}*start;
int main()
{
	clrscr();
	add_begin(23);
	add_end(10);
	add_begin(5);
	add_middle(87,2);
	display();
	getch();
}
void add_begin(int num)
{
	struct employee *temp;
	temp = (struct employee *) malloc (sizeof(struct employee));
	temp -> info = num;
	temp -> link = start;
	start = temp;
}
void add_middle(int num , int pos)
{
	int i;
	struct employee *temp , *disp;
	temp = (struct employee *) malloc (sizeof(struct employee));
	temp -> info = num;
	disp = start;
	for ( i = 0; i < pos - 1; i++)
	{
		disp = disp -> link;
		if ( disp -> link == NULL)
		{
			printf("The element cannot insert at position %d", pos);
			exit(1);
		}
	}
	temp -> link = disp -> link;
	disp -> link = temp;
}
void add_end(int num)
{
	struct employee *temp , *disp;
	temp = (struct employee *) malloc(sizeof(struct employee));
	temp -> info = num;
	temp -> link = NULL;
	if ( start == NULL)
	{
		start = temp;
	}
	else
	{
		disp = start;
		while ( disp -> link != NULL)
			disp = disp -> link;
		disp -> link = temp;
	}
}
void display()
{
	struct employee *disp;
	disp = start;
	clrscr();
	while ( disp != NULL)
	{
		printf("%d ",disp -> info);
		disp = disp -> link;
	}
}
