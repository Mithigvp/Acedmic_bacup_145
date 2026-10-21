
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int row, col, data;
    struct node *right, *down;
};

struct node *rowHead[10];
struct node *colHead[10];
int a[10][10];
int m, n, created = 0;

void create()
{
    int i, j;
    struct node *p, *rtail[10], *ctail[10];

    if (created == 1)
    {
        printf("Matrix already created!\n");
        return;
    }

    printf("Enter rows and columns (max 10): ");
    scanf("%d%d", &m, &n);

    if (m < 1 || m > 10 || n < 1 || n > 10)
    {
        printf("Invalid matrix size!\n");
        return;
    }

    for (i = 0; i < m; i++)
    {
        rowHead[i] = NULL;
        rtail[i] = NULL;
    }

    for (j = 0; j < n; j++)
    {
        colHead[j] = NULL;
        ctail[j] = NULL;
    }

    printf("Enter matrix elements:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);

            if (a[i][j] != 0)
            {
                p = (struct node *)malloc(sizeof(struct node));

                if (p == NULL)
                {
                    printf("Memory allocation failed!\n");
                    exit(1);
                }

                p->row = i;
                p->col = j;
                p->data = a[i][j];
                p->right = NULL;
                p->down = NULL;

                if (rowHead[i] == NULL)
                    rowHead[i] = p;
                else
                    rtail[i]->right = p;

                rtail[i] = p;

                if (colHead[j] == NULL)
                    colHead[j] = p;
                else
                    ctail[j]->down = p;

                ctail[j] = p;
            }
        }
    }

    created = 1;
    printf("Sparse matrix created successfully!\n");
}

void display()
{
    int i, j;
    struct node *p;

    if (created == 0)
    {
        printf("Please create the matrix first!\n");
        return;
    }

    printf("\nSparse Matrix:\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%4d", a[i][j]);

        printf("\n");
    }

    printf("\nNon-zero elements (row, column, value):\n");

    for (i = 0; i < m; i++)
    {
        p = rowHead[i];

        while (p != NULL)
        {
            printf("(%d, %d, %d)\n",
                   p->row, p->col, p->data);
            p = p->right;
        }
    }
}

void main()
{
    int choice;


    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Create Sparse Matrix\n");
        printf("2. Display Sparse Matrix\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 3);

    getch();
}
