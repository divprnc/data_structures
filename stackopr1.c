extern int arr[10];
int top = -1;

void push()
{
	if (top == 9)
	{
		printf("Stack Overflow");
		getch();
	}
	else
	{
		printf("Enter the element : ");
		scanf("%d", &arr[++top]);
	}
}

void pop()
{
	if (top == -1)
	{
		printf("Stack Underflow");
		getch();
	}
	else
	{
		arr[top] = 0;
		--top;
	}
	printf("Data Deleted");
}

void display()
{
	int i;
	printf("Array Elements are....................\n");
	for (i = 0; i <= top; i++)
	{
		printf("%d  ", arr[i]);
	}
}

void asort()
{
	int i, j, temp;
	for (i = 0; i < top; i++)
	{
		for (j = i + 1; j <= top; j++)
		{
			if (arr[j] < arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("Data Sorted");
}

void dsort()
{
	int i, j, temp;
	for (i = 0; i < top; i++)
	{
		for (j = i + 1; j <= top; j++)
		{
			if (arr[j] > arr[i])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	printf("Data Sorted");
}

void reverse()
{
	int i, count, temp;
	count = top;
	
	for (i = 0; i <= top / 2; i++) // Reverse operation will take place half of the total element
	{
		temp = arr[i];
		arr[i] = arr[count];
		arr[count] = temp;
		count--;
	}
	printf("Data Reversed");
}

void search()
{
	int i, search;
	printf("Enter the data to be search : ");
	scanf("%d", &search);
	
	for (i = 0; i <= top; i++)
	{
		if (search == arr[i])
		{
			printf("%d is at %d position", search, (i + 1));
		}
	}
	
	if (i > top)
	{
		printf("Data Not Found");
	}
}
