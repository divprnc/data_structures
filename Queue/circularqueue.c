// WAP to demonstrate circular queue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int arr[SIZE];
int rear = -1, front = -1;

void enqueue(int);
void dequeue();
void display();
	
void main()
{
	system("CLS");
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(50);
	enqueue(60);
	enqueue(70);
	enqueue(80);
	enqueue(90);
	enqueue(100);
	display();
	dequeue();
	display();
	dequeue();
	display();
	dequeue();
	display();
	enqueue(10);
	printf("\n");
	display();
	enqueue(20);
	display();
	enqueue(30);
	display();
	enqueue(40);
	display();
}

void enqueue(int n)
{
	if (rear == SIZE - 1 && front == rear + 1 || front == rear + 1)
	{
		printf("Queue is full\n");
		exit(1);
	}
	if (rear == SIZE - 1 && front != -1)
	{
		rear = -1;
	}
	arr[++rear] = n;
	if (front == -1)
	{
		front = 0;
	}
}

void dequeue()
{
	if (front == SIZE)
	{
		printf("Queue is Empty. Cannot delete.\n");
		getch();
		rear = -1;
		//exit(1);
	}	
	++front;
}

void display()
{
	int i;
	if (front == -1 && rear == -1)
	{
		printf("No Element in the queue\n");
	}
	//front++;
	if (rear > front)
	{
		for (i = front; i <= rear; i++)
		{
			printf("%d ", arr[i]);
		}
	}
	else
	{
		if (front != 0)
		{
			for (i = front; i <= (SIZE - 1); i++)
			{
				printf("%d ", arr[i]);
			}
			for (i = 0; i <= rear; i++)
			{
				printf("%d ", arr[i]);
			}
		}
	}
	printf("\n");
}
