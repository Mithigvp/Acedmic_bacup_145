#include <stdio.h>
#include <conio.h>

#define SIZE 50

void main()
{
	void push(char st[], char value, int *top);
    char pop(char st[], int *top);
    int checkPriority(char ch);
    void prefix(char s[], int *top);

    char s[SIZE];
    int top = -1;

    printf("Enter Infix Expression : ");
    scanf("%s", s);

    printf("Prefix Expression : ");
    prefix(s, &top);

    getch();
    return;
}

void push(char st[], char value, int *top)
{
    if(*top == SIZE - 1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        (*top)++;
        st[*top] = value;
    }
}

char pop(char st[], int *top)
{
    char value;

    if(*top == -1)
    {
	printf("\nStack Underflow");
	return '\0';
    }

    value = st[*top];
    (*top)--;

    return value;
}

int checkPriority(char ch)
{
    if(ch == '+' || ch == '-')
	return 1;

    else if(ch == '*' || ch == '/')
	return 2;

    else
	return 0;
}

void prefix(char s[], int *top)
{
    int length;
    int i;
    int j;
    char ch;
    char st[SIZE];
    char ans[SIZE];

    length = 0;
    j = 0;

    while(s[length] != '#')
    {
	length++;
    }

    for(i = length - 1; i >= 0; i--)
    {
	ch = s[i];

	if(ch == ')')
	{
	    push(st, ch, top);
	}
	else if(ch == '(')
	{
	    while(*top != -1 && st[*top] != ')')
	    {
		ans[j++] = pop(st, top);
	    }

	    if(*top != -1)
	    {
		pop(st, top);
	    }
	}
	else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
	{
	    while(*top != -1 && checkPriority(st[*top]) > checkPriority(ch))
	    {
		ans[j++] = pop(st, top);
	    }

	    push(st, ch, top);
	}
	else
	{
	    ans[j++] = ch;
	}
    }

    while(*top != -1)
    {
	ans[j++] = pop(st, top);
    }

    ans[j] = '\0';

    for(i = j - 1; i >= 0; i--)
    {
	printf("%c", ans[i]);
    }

    printf("\n");
}