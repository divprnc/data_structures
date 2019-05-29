// WAP to demonstrate DMA
#include <stdio.h>
#include <malloc.h>

void main()
{
	system("CLS");
	int *a, n, n_more, i, sum = 0, total_memory;
	printf("How much memory you want to allocate ? ");
	scanf("%d", &n);
	a = malloc(sizeof(int) * n); // calloc(sizeof(int), n)
	
	if (a == NULL)
	{
		printf("Memory not allocated");
		getch();
		return;
	}
	else
	{
		for(i = 0; i < n; i++)
		{
			printf("Enter the element : ");
			scanf("%d", &a[i]);
		}
	}
	
	printf("How much more memory you want to allocate ? ");
	scanf("%d", &n_more);
	
	total_memory= n + n_more;
	
	a = (int *) realloc(a, sizeof(int) * n_more); 
	
	for(i = 0; i < n_more; i++)
	{
		printf("Enter the element : ");
		scanf("%d", &a[n++]);
	}
	
	for (i = 0; i < total_memory; i++)
	{
		sum += a[i];
	}
	printf("Sum = %d", sum);
	free(a);
}
