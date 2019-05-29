// program to insert node in the linked list and display the item of the node
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#define clrscr() ("CLS")
void add(int);
void display();
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
	add(5);
	getch();
}
void add(int num)
{
	struct employee *temp;
	temp = (struct employee *) malloc(sizeof(struct employee));
	temp -> info = num;
	temp -> link = NULL;
	if ( start == NULL)
		start = temp;
	else
		start -> link = temp;
}
void display()
{
	while ( start != NULL)
	{
		printf("%d",start -> info);
		start = start -> link;
	}
}
