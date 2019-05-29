// Program to demonstrate add node at the last of linked list
#include <stdio.h>
#include <malloc.h>

struct Test
{
	int num;
	struct Test *link;
}*start;

void main()
{
	system("CLS");
	add(10);	
	add(20);
	add(30);
	add(40);
	add(50);
	display();
}

void add(int n)
{
	struct Test *temp, *disp;
	temp = (struct Test *) malloc (sizeof(struct Test));
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
	temp -> num = n;
	temp -> link = NULL;
}

void display()
{
	struct Test *disp;
	disp = start;
	while (disp != NULL)
	{
		printf("%d ", disp -> num);
		disp = disp -> link;
	}
}
