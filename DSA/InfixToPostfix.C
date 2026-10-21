#include<stdio.h>
#include<conio.h>

#define MAX 50

void push(int *, char [], char);
char pop(int *, char []);
int priority(char);
void InfixToPostfix(char [], int *);
void InfixToPrefix(char [], int *);

void main()
{
    char s[MAX];
    int top;

    printf("Enter Infix Expression= : ");
    scanf("%s", s);

    top = -1;
    printf("\nPostfix Expression= : ");
    InfixToPostfix(s, &top);

    top = -1;
    printf("\nPrefix Expression= : ");
    InfixToPrefix(s, &top);

    getch();
}

void push(int *top, char stack[], char ch)
{
    if(*top == MAX-1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        (*top)++;
        stack[*top] = ch;
    }
}

char pop(int *top, char stack[])
{
    char ch;

    if(*top == -1)
    {
        return '\0';
    }

    ch = stack[*top];
    (*top)--;

    return ch;
}

int priority(char ch)
{
    if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}



void InfixToPostfix(char s[], int *top)
{
    int i = 0;
    char ch;
    char stack[MAX];

    while((ch = s[i]) != '#')
    {
        if((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9'))
        {
            printf("%c", ch);
        }
        else if(ch == '(')
        {
            push(top, stack, ch);
        }
        else if(ch == ')')
        {
            while(*top != -1 && stack[*top] != '(')
            {
                printf("%c", pop(top, stack));
            }

            if(*top != -1)
                pop(top, stack);
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            while(*top != -1 &&
                  stack[*top] != '(' &&
                  priority(stack[*top]) >= priority(ch))
            {
                printf("%c", pop(top, stack));
            }

            push(top, stack, ch);
        }

        i++;
    }

    while(*top != -1)
    {
        printf("%c", pop(top, stack));
    }
}



void InfixToPrefix(char s[], int *top)
{
    int length = 0;
    int i, j = 0;
    char ch;
    char stack[MAX];
    char ans[MAX];

    while(s[length] != '#')
    {
        length++;
    }

    for(i = length-1; i >= 0; i--)
    {
        ch = s[i];

        if((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9'))
        {
            ans[j++] = ch;
        }
        else if(ch == ')')
        {
            push(top, stack, ch);
        }
        else if(ch == '(')
        {
            while(*top != -1 && stack[*top] != ')')
            {
                ans[j++] = pop(top, stack);
            }

            if(*top != -1)
                pop(top, stack);
        }
        else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
        {
            while(*top != -1 &&
                  priority(stack[*top]) > priority(ch))
            {
                ans[j++] = pop(top, stack);
            }

            push(top, stack, ch);
        }
    }

    while(*top != -1)
    {
        ans[j++] = pop(top, stack);
    }

    ans[j] = '\0';

    for(i=j-1; i>=0; i--)
    {
        printf("%c", ans[i]);
    }
}