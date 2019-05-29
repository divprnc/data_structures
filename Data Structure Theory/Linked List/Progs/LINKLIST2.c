// program to insert node at the begining and end and display the item of the node
#include <stdio.h>
#include<conio.h>
#include <malloc.h>
#include <stdlib.h>
#define clrscr() ("CLS")
void add(int);
void display();
void add_begin(int);
struct employee
{
	int info;
	struct employee *link; // self referential structure
}*start;
void main()
{
	clrscr();
	add(10);
	add(20);
	display();
	add_begin(5);
	display();
	add(25);
	display();
	add(30);
	display();
	add_begin(40);
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
void add(int num)
{
	struct employee *temp , *disp;
	temp = (struct employee *) malloc(sizeof(struct employee));
	temp -> info = num;
	temp -> link = NULL;
	if ( start == NULL)
		start = temp;
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
