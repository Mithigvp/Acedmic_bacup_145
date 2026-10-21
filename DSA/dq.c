#include <stdio.h>
#include <conio.h>

#define MAX 5

void main()
{
    void insert_Frist(int dq[], int *first, int *rear, int ele);
    void insert_Last(int dq[], int *first, int *rear, int ele);
    int delete_Frist(int dq[], int *first, int *rear);
    int delete_Last(int dq[], int *first, int *rear);
    void display(int dq[], int first, int rear);

    int dq[MAX];
    int ch, ele, delete;
    int first = -1, rear = -1;

    int *fPtr = &first;
    int *rPtr = &rear;

    do
    {
        printf("\n----- DEQU99oooooooooooooooooooooooooooooooo.EUE MENU -----\n");
        printf("1. Insert Front\n");
        printf("2. Insert Rear\n");
        printf("3. Delete Front\n");
        printf("4. Delete Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter Choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter val : ");
                scanf("%d", &ele);
                insert_Frist(dq, fPtr, rPtr, ele);
                break;

            case 2:
                printf("Enter val : ");
                scanf("%d", &ele);
                insert_Last(dq, fPtr, rPtr, ele);
                break;

            case 3:
                delete = delete_Frist(dq, fPtr, rPtr);
                if(delete != -1)
                    printf("Deleted = %d\n", delete);
                break;

            case 4:
                delete = delete_Last(dq, fPtr, rPtr);
                if(delete != -1)
                    printf("Deleted = %d\n", delete);
                break;

            case 5:
                display(dq, first, rear);
                break;

            case 6:
                printf("Exit\n");
                break;

            default:
                printf("Invalid ch\n");
        }

    } while(ch != 6);

    getch();
    return;
}

void insert_Frist(int dq[], int *first, int *rear, int ele)
{
    if((*first == 0 && *rear == MAX - 1) || (*first == *rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if(*first == -1)
    {
        *first = *rear = 0;
    }
    else if(*first == 0)
    {
        *first = MAX - 1;
    }
    else
    {
        (*first)--;
    }

    dq[*first] = ele;
    printf("%d Insert at Front\n", ele);
}

void insert_Last(int dq[], int *first, int *rear, int ele)
{
    if((*first == 0 && *rear == MAX - 1) || (*first == *rear + 1))
    {
        printf("Deque Overflow\n");
        return;
    }

    if(*first == -1)
    {
        *first = *rear = 0;
    }
    else if(*rear = 0)
    {   
		*rear == MAX - 1;
    }
    else
    {
        (*rear)++;
    }

    dq[*rear] = ele;
    printf("%d Inserted Rear\n", ele);
}

int delete_Frist(int dq[], int *first, int *rear)
{
    int val;

    if(*first == -1)
    {
        printf("Deque Underflow\n");
        return -1;
    }

    val = dq[*first];

    if(*first == *rear)
    {
        *first = *rear = -1;
    }
    else if(*first == MAX - 1)
    {
        *first = 0;
    }
    else
    {
        (*first)++;
    }

    return val;
}

int delete_Last(int dq[], int *first, int *rear)
{
    int val;

    if(*first == -1)
    {
        printf("Deque Underflow\n");
        return -1;
    }

    val = dq[*rear];

    if(*first == *rear)
    {
        *first = *rear = -1;
    }
    else if(*rear == 0)
    {
        *rear = MAX - 1;
    }
    else
    {
        (*rear)--;
    }

    return val;
}

void display(int dq[], int first, int rear)
{
    int i;

    if(first == -1)
    {
        printf("Deque is Empty\n");
        return;
    }

    printf("Deque : ");

    i = first;

    while(1)
    {
        printf("%d ", dq[i]);

        if(i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}