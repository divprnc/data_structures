// Implementation of single linked list
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#define clrscr() ("CLS")
void create();
void insert();
void insert_begin();
void insert_at_pos();
void insert_end();
void delete();
void delete_begin();
void delete_at_pos();
void delete_end();
void search();
void display();
void total_data();
void get_data(struct employee *);
void print_data(struct employee *);
typedef struct employee
{
	int empno;
	char ename[10];
	int sal;
	struct employee *link;
}EMP;
EMP *emp;
int main()
{
	int choice;
	while (1)
	{
		clrscr();
		printf("Menu");
		printf("\n");
		printf("=============");
		printf("\n");
		printf("1. Create \n2. Insert \n3. Display \n4. Delete \n5. Search \n6. Total Data \n7. Exit");
		printf("\nEnter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			create();
			break;
		case 2:
			insert();
			break;
		case 3:
			display();
			break;
		case 4:
			delete();
			break;
		case 5:
			search();
			break;
		case 6:
			total_data();
			break;
		case 7:
			exit(1);
		default:
			printf("Invalid Choice");
		}
	}
	getch();
}
void create()
{
	char ch;
	do
	{
		EMP *temp , *last;
		clrscr();
		temp = (EMP *) malloc (sizeof(EMP));
		get_data(temp);
		temp -> link = NULL;
		if (emp == NULL)
			emp = temp;
		else
		{
			last = emp;
			while (last -> link != NULL)
				last = last -> link;
			last -> link = temp;
		}
			printf("Do you want to insert another link:");
			ch = getch();
	}	while (ch == 'y' || ch == 'Y');
}
void insert()
{
	int choice;
	do
	{
		clrscr();
		printf("1. Insert at beginning");
		printf("\n2. Insert at position");
		printf("\n3. Insert at the end");
		printf("\n4. Exit");
		printf("\nEnter your choice:");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				insert_begin();
				break;
			case 2:
				insert_at_pos();
				break;
			case 3:
				insert_end();
				break;
			case 4:
				return;
			default:
				printf("Invalid Choice");
		}
	}while (choice);
}
void delete()
{
	int choice;
	clrscr();
	printf("1. Delete at beginning");
	printf("\n2. Delete at any position");
	printf("\n3. Delete at end");
	printf("\nEnter your choice:");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		delete_begin();
		break;
	case 2:
		delete_at_pos();
		break;
	case 3:
		delete_end();
		break;
	default:
		printf("Invalid choice");
	}
}
void insert_begin()
{
	EMP *temp;
	clrscr();
	temp = (EMP *) malloc (sizeof(EMP));
	get_data(temp);
	if (emp == NULL)
	{
		emp = temp;
		temp -> link = NULL;
	}
	else
	{
		temp -> link = emp;
		emp = temp;
	}
}
void insert_at_pos()
{
	int pos , i;
	EMP *temp , *last;
	temp = (EMP *) malloc (sizeof(EMP));
	clrscr();
	printf("Enter the index number:");
	scanf("%d", &pos);
	if (pos==0)
	{
		printf("Index number must be greater than 0");
		getch();
		return;
	}
	last = emp;
	for ( i =0; i < pos -1; i++)
	{
		last = last -> link;
		if ( last -> link == NULL)
		{
			printf("The element cannot be inserted at index %d", pos);
			getch();
			return;
		}
	}
	get_data(temp);
	temp -> link = last -> link;
	last -> link = temp;
}
void insert_end()
{
	EMP *temp , *last;
	temp = (EMP *) malloc (sizeof(EMP));
	clrscr();
	last = emp;
	while ( last -> link != NULL)
		last = last -> link;
	get_data(temp);
	last -> link = temp;
	temp -> link = NULL;
}
void delete_begin()
{
	EMP *temp;
	if ( emp == NULL)
		printf("List is empty");
	else
	{
		temp = emp;
		emp = emp -> link;
		temp = NULL;
		free(temp);
	}
}
void delete_at_pos()
{
	int pos, i;
	EMP *temp , *last;
	clrscr();
	printf("Enter the index number:");
	scanf("%d", &pos);
	temp = emp;
	for ( i = 0; i < pos - 1; i++)
	{
		temp = temp -> link;
		if ( temp -> link  == NULL)
		{
			printf("Deletion is not possible");
			getch();
			return;
		}
	}
	last = temp -> link;
	temp -> link = last -> link;
	last -> link = NULL;
	free(last);
}
void delete_end()
{
	EMP *temp , *last;
	temp = emp;
	while (temp -> link != NULL)
	{
		last = temp;
		temp = temp -> link;
	}
	last -> link = NULL;
	free(temp);
}
void search()
{
	int element;
	EMP *temp;
	clrscr();
	printf("Enter the element to search:");
	scanf("%d", &element);
	temp = emp;
	while (temp != NULL)
	{
		if (element == temp -> empno)
		{
			print_data(temp);
			break;
		}
		temp = temp -> link;
	}
	if (temp == NULL)
		printf("Element Not Exist");
	getch();
}
void display()
{
	EMP *temp;
	clrscr();
	temp = emp;
	while ( temp != NULL)
	{
		print_data(temp);
		printf("\n\n");
		temp = temp -> link;
	}
	getch();
}
void total_data()
{
	int count = 0;
	EMP *temp;
	clrscr();
	temp = emp;
	while (temp != NULL)
	{
		++count;
		temp = temp -> link;
	}
	printf("Total no. of data: %d", count);
	getch();
}
void get_data(EMP *temp)
{
	printf("Enter the empno:");
	scanf("%d", &temp -> empno);
	printf("Enter the ename:");
	scanf("%s" ,&temp -> ename);
	printf("Enter the salary:");
	scanf("%d", &temp -> sal);
}
void print_data(EMP *temp)
{
	printf("Empno: %d", temp -> empno);
	printf("\nEname: %s", temp -> ename);
	printf("\nSalary: %d", temp -> sal);
}
