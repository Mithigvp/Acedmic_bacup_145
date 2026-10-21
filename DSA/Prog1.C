#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void push(int *, int[], int);
int pop(int *, int[]);
void peek(int *, int[]);
void display(int *, int[]);

int main()
{
    int *top, nval, del, t;
    int stack[MAX];
    int ch;

    t = -1;
    top = &t;

    while (1)
    {
        printf("\nEnter 1 for Push\n");
        printf("Enter 2 for Pop\n");
        printf("Enter 3 for Display\n");
        printf("Enter 4 for Peek\n");
        printf("Enter 0 for Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &nval);
            push(top, stack, nval);
            break;

        case 2:
            del = pop(top, stack);
            if (t != -1 || del != 0)
                printf("\nPopped value is: %d\n", del);
            break;

        case 3:
            display(top, stack);
            break;

        case 4:
            peek(top, stack);
            break;

        case 0:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

void push(int *t, int s[], int val)
{
    if (*t < MAX - 1)
    {
        (*t)++;
        s[*t] = val;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int pop(int *t, int s[])
{
    int rem = 0;

    if (*t == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        rem = s[*t];
        (*t)--;
    }

    return rem;
}

void display(int *t, int s[])
{
    int i;

    if (*t == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Stack Elements:\n");
        for (i = *t; i >= 0; i--)
        {
            printf("%d\n", s[i]);
        }
    }
}

void peek(int *t, int s[])
{
    if (*t == -1)
    {
        printf("Stack is Empty\n");
    }
    else
    {
        printf("Top element is: %d\n", s[*t]);
    }
}