#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

/* Function Prototypes */
void insert(struct node **head, int val);
int delete_ll(struct node **head, int dval);
void display(struct node *head);

void main()
{
    struct node *head = NULL;
    int choice, val, dval;

    while (1)
    {

        printf("\n========== LINKED LIST MENU ==========\n");
        printf("1. Insert Node\n");
        printf("2. Delete Node\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nEnter value to insert : ");
                scanf("%d", &val);
                insert(&head, val);
                break;

            case 2:
                printf("\nEnter value to delete : ");
                scanf("%d", &dval);

                if (delete_ll(&head, dval))
                    printf("\nNode deleted successfully.");
                else
                    printf("\nValue not found.");

                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("\nProgram Terminated...");
                getch();
                exit(0);

            default:
                printf("\nInvalid Choice!");
        }

        printf("\n\nPress any key to continue...");
        getch();
    }
}

/* Insert at Beginning */

void insert(struct node **head, int val)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\nMemory Allocation Failed.");
        return;
    }

    newnode->data = val;
    newnode->next = *head;
    *head = newnode;

    printf("\nValue %d inserted successfully.", val);
}

/* Delete Node */

int delete_ll(struct node **head, int dval)
{
    struct node *curr, *prev;

    curr = *head;
    prev = NULL;

    if (curr == NULL)
    {
        printf("\nLinked List is Empty.");
        return 0;
    }

    while (curr != NULL && curr->data != dval)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        return 0;
    }

    if (prev == NULL)
    {
        *head = curr->next;
    }
    else
    {
        prev->next = curr->next;
    }

    free(curr);

    return 1;
}

/* Display Linked List */

void display(struct node *head)
{
    struct node *temp;

    temp = head;

    if (temp == NULL)
    {
        printf("\nLinked List is Empty.");
        return;
    }

    printf("\n\nCurrent Linked List:\n\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL");
}