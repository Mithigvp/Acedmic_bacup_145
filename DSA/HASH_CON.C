#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 10

int hash_func(int key)
{
	return key % SIZE;
}

void allocate(int ring[])
{
	int key, idx, i;
	printf("\n Enter element to allocate: ");
	scanf("%d", &key);
	
	idx = hash_func(key);
	i = 0;
	
	while(ring[idx] != 0 && i < SIZE)
	{
		idx = (idx + 1) % SIZE;
		i++;
	}
	
	if(i == SIZE)
	{
		printf("\n Hash ring is full!");
	}
	else
	{
		ring[idx] = key;
		printf("\n Element %d allocated successfully at ring index %d.", key, idx);
	}
}

void deallocate(int ring[])
{
	int key, idx, i, found = 0;
	printf("\n Enter element to deallocate: ");
	scanf("%d", &key);
	
	idx = hash_func(key);
	i = 0;
	
	while(i < SIZE)
	{
		if(ring[idx] == key)
		{
			ring[idx] = 0;
			found = 1;
			printf("\n Element %d deallocated successfully from index %d.", key, idx);
			break;
		}
		idx = (idx + 1) % SIZE;
		i++;
	}
	
	if(!found)
	{
		printf("\n Element not found in the hash ring.");
	}
}

void main()
{
	int ring[SIZE] = {0};
	int choice;

	clrscr();

	while(1)
	{
		printf("\n\n--- CONSISTENT HASHING MENU ---");
		printf("\n1. Allocation");
		printf("\n2. Deallocate");
		printf("\n3. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				allocate(ring);
				break;

			case 2:
				deallocate(ring);
				break;

			case 3:
				exit(0);

			default:
				printf("\n Invalid Choice! Please try again.");
		}
	}

	getch();
}