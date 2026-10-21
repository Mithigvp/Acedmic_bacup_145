#include <stdio.h>
#include <conio.h>

#define max 5

int main()
{
	void push(int *, int[], int);
	int pop(int *, int[]);
	void display(int *, int[]);
	int stack[max];
	int top = -1;
	int ch, newele, rmele;

	clrscr();

    do
    {
	printf("\n ---Stack Menu--- \n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Display\n");
	printf("4. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &ch);

	switch(ch)
	{
	    case 1:
		printf("Enter the element: ");
		scanf("%d", &newele);
		push(&top, stack, newele);
		break;

	    case 2:
		rmele = pop(&top, stack);
		if(rmele != -1)
		{
		    printf("Removed element: %d\n", rmele);
		}
		break;

	    case 3:
		display(&top, stack);
		break;

	    case 4:
		printf("Program Ended.\n");
		break;

	    default:
		printf("Invalid Choice!\n");
	}

    } while(ch != 4);
    getch();
    return 0;
}

void push(int *t, int s[], int ele)
{
    if(*t < max - 1)
    {
	*t = *t+1;
	s[*t] = ele;
	printf("Element inserted successfully.\n");
    }
    else
    {
	printf("Stack Overflow\n");
    }
}

int pop(int *t, int s[])
{
    int rele;

    if(*t >= 0)
    {
	rele = s[*t];
	*t = *t-1;
	return rele;
    }
    else
    {
	printf("Stack Underflow\n");
	return -1;
    }
}

void display(int *t, int s[])
{
    int i;

    if(*t == -1)
    {
	printf("Stack is Empty\n");
	return;
    }

    printf("Stack Elements:\n");

    for(i = *t; i >= 0; i--)
    {
	printf("%d\n", s[i]);
    }
}