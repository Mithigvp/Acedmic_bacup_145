#include <stdio.h>
#include <conio.h>

#define SIZE 5

void main()
{
    void push(int q[], int *first, int *rear, int val);
    int pop(int q[], int *first, int *rear);
    void display(int q[], int first, int rear);

    int q[SIZE];
    int first = -1, rear = -1;
    int ch, val, result;

    int *firstPtr = &first;
    int *rearPtr = &rear;
   
    do
    {
	printf("\n-----Queue Menu-----\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Display\n");
	printf("4. Exit\n");

	printf("Enter Choice : ");
	scanf("%d", &ch);

	switch(ch)
	{
	    case 1:
		printf("Enter Value : ");
		scanf("%d", &val);

		push(q, firstPtr, rearPtr, val);
		break;

	    case 2:
		result = pop(q, firstPtr, rearPtr);

		if(result != -1)
		    printf("Deleted = %d\n", result);

		break;

	    case 3:
		display(q, first, rear);
		break;

	    case 4:
		printf("Exit\n");
		break;

	    default:
		printf("Invalid Choice\n");
	}

    } while(ch != 4);

    getch();
    return;
}

void push(int q[], int *first, int *rear, int val)
{
    if(*first == -1 && *rear == -1)
    {
        *first = *rear = 0;
        q[*rear] = val;
    }
    else if(*rear < SIZE - 1)
    {
        (*rear)++;
        q[*rear] = val;
    }
    else
    {
        printf("Queue Overflow\n");
    }
}

int pop(int q[], int *first, int *rear)
{
    int value;

    if(*first == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    if(*first == *rear)
    {
        value = q[*first];
        *first = *rear = -1;
    }
    else
    {
        value = q[*first];
        (*first)++;
    }

    return value;
}

void display(int q[], int first, int rear)
{
    int ele;

    if(first == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue : ");

    for(ele = first; ele <= rear; ele++)
    {
        printf("%d ", q[ele]);
    }

    printf("\n");
}