// WAP to add node at any position in the linked list
#include <stdio.h>
#include <malloc.h>

void add_end(int);
void add_middle(int);
void display();

typedef struct Test
{
	int num;
	struct Temp *link; // self referential structure
}T;
T *start; // head node

void main()
{
	system("CLS");
	add_end(10);
	add_end(20);
	add_end(30);
	add_end(40);
	display();
	add_middle(50);
	display();
}

void add_end(int n)
{
	T *temp, *disp;
	temp = (T *) malloc (sizeof(T));
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
	temp = NULL;
	disp = NULL;
	free(temp);
	free(disp);
}

void add_middle(int n)
{
	T *disp, *temp;
	int pos, i;
	printf("\nEnter the position where you want to add : ");
	scanf("%d", &pos);
	if (pos <= 1)
	{
		printf("Insertion at this position is not valid");
		exit(1);
	}
	
	temp = (T *) malloc (sizeof(T));
	temp -> num = n;
	disp = start;
	for (i = 1; i < (pos - 1); i++)
	{
		disp = disp -> link;
	}
	temp -> link = disp -> link;
	disp -> link = temp;
	disp = NULL;
	temp= NULL;
	free(disp);
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
