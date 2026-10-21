#include <stdio.h>
#include <conio.h>

#define MAX 5

int main()
{
    void insert(int cq[], int *frist, int *rear, int ele);
    int deleted(int cq[], int *frist, int *rear);
    void display(int cq[], int frist, int rear);

    int cq[MAX];
    int ch, ele, delete;
    int frist = -1, rear = -1;
    int *fptr = &frist;
    int *rptr = &rear;


    do
    {
	printf("\n---- Circular Queue ----\n");
	printf("1. insert\n");
	printf("2. deleted\n");
	printf("3. Display\n");
	printf("4. Exit\n");

	printf("Enter your choice : ");
	scanf("%d", &ch);

	switch(ch)
	{
	    case 1:
		printf("Enter value : ");
		scanf("%d", &ele);
		insert(cq, fptr, rptr, ele);
		break;

	    case 2:
		delete = deleted(cq, fptr, rptr);
		if(delete != -1)
		    printf("Deleted Element = %d\n", delete);
		break;

	    case 3:
		display(cq, frist, rear);
		break;

	    case 4:
		printf("Exit Queue\n");
		break;

	    default:
		printf("Invalid Choice\n");
	}

    } while(ch != 4);

    getch();
    return 0;
}

void insert(int cq[], int *frist, int *rear, int ele)
{
    if((*frist == 0 && *rear == MAX - 1) || (*frist == *rear + 1))
    {
        printf("Queue Overflow\n");
        return;
    }

    if(*frist == -1)
    {
        *frist = 0;
        *rear = 0;
    }
    else if(*rear == MAX - 1)
    {
        *rear = 0;
    }
    else
    {
        (*rear)++;
    }

    cq[*rear] = ele;
}

int deleted(int cq[], int *frist, int *rear)
{
    int ele;

    if(*frist == -1)
    {
        printf("Queue Underflow\n");
        return -1;
    }

    ele = cq[*frist];

    if(*frist == *rear)
    {
        *frist = -1;
        *rear = -1;
    }
    else if(*frist == MAX - 1)
    {
        *frist = 0;
    }
    else
    {
        (*frist)++;
    }

    return ele;
}

void display(int cq[], int frist, int rear)
{
    int i;

    if(frist == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    i = frist;

    while(1)
    {
        printf("%d ", cq[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}