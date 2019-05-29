// Program to demonstrate stack operation
#include <stdio.h>
#include "stackopr1.c"
int arr[10];

void push();
void pop();
void display();
void asort();
void dsort();
void reverse();
void search();

void main()
{
	int choice;
	do	
	{
		system("CLS");
		printf("Menu\n==========================\n");
		printf("1. Add\n2. Delete\n3. Display\n4. Ascending Sort\n5. Descending Sort\n6. Reverse\n7. Search\n8. Exit\n\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				system("CLS");
				push();
				break;
			case 2:
				system("CLS");
				pop();
				getch();
				break;
			case 3:
				system("CLS");
				display();
				getch();
				break;
			case 4:
				system("CLS");
				asort();
				getch();
				break;
			case 5:
				system("CLS");
				dsort();
				getch();
				break;
			case 6:
				system("CLS");
				reverse();
				getch();
				break;
			case 7:
				system("CLS");
				search();
				getch();
				break;
			case 8:
				exit(1);
			default:
				system("CLS");
				printf("Invalid Choice");
				getch();
		}		
	}while(1);
}
