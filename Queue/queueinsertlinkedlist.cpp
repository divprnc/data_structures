// WAP to demonstrate insert and delete node in the queue
#include <stdio.h>
#include <malloc.h>
typedef struct Test
{
	int num;
	struct Test *link;
}T;
T *rear = NULL;
T *front = NULL;
	
void enqueue(int);
void dequeue();
void display();
	
void main()
{
	system("CLS");
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(50);
	enqueue(40);
	display();
	printf("\n");
	dequeue();
	display();
	printf("\n");
	dequeue();
	display();
}

void enqueue(int n)
{
	T *temp;
	temp = (T *) malloc (sizeof(T));
	temp -> num = n;
	temp -> link = NULL;
	
	if (rear == NULL)
	{
		rear = temp;
		front = temp;	
	}
	else
	{
		rear -> link = temp;
		rear = temp;
	}
	rear -> link =temp;
	temp = NULL;
	free(temp);
}

void dequeue()
{
	T *temp;
	temp = front;
	front = temp -> link;
	temp -> link = NULL;
	free(temp);
}

void display()
{
	T *temp;
	temp = front;
	while (temp != NULL)
	{
		printf("%d ", temp -> num);
		temp = temp -> link;
	}
	free(temp);
}
