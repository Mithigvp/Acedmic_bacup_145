
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 10

struct node
{
    int row, col, data;
    struct node *right, *down;
};

struct node *rowHead1[MAX], *colHead1[MAX];
struct node *rowHead2[MAX], *colHead2[MAX];
struct node *rowHead3[MAX], *colHead3[MAX];

int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
int m, n, created = 0;

void createMatrix(int x[MAX][MAX],
                  struct node *rh[MAX],
                  struct node *ch[MAX],
                  int rows, int cols)
{
    int i, j;
    struct node *p, *rtail[MAX], *ctail[MAX];

    for (i = 0; i < rows; i++)
    {
        rh[i] = NULL;
        rtail[i] = NULL;
    }

    for (j = 0; j < cols; j++)
    {
        ch[j] = NULL;
        ctail[j] = NULL;
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &x[i][j]);

            if (x[i][j] != 0)
            {
                p = (struct node *)malloc(sizeof(struct node));

                if (p == NULL)
                {
                    printf("Memory allocation failed!\n");
                    exit(1);
                }

                p->row = i;
                p->col = j;
                p->data = x[i][j];
                p->right = NULL;
                p->down = NULL;

                if (rh[i] == NULL)
                    rh[i] = p;
                else
                    rtail[i]->right = p;

                rtail[i] = p;

                if (ch[j] == NULL)
                    ch[j] = p;
                else
                    ctail[j]->down = p;

                ctail[j] = p;
            }
        }
    }
}

void create()
{
    if (created)
    {
        printf("Matrices already created!\n");
        return;
    }

    printf("Enter rows and columns (max 10): ");
    scanf("%d%d", &m, &n);

    if (m < 1 || m > MAX || n < 1 || n > MAX)
    {
        printf("Invalid matrix size!\n");
        return;
    }

    printf("Enter elements of Matrix A:\n");
    createMatrix(a, rowHead1, colHead1, m, n);

    printf("Enter elements of Matrix B:\n");
    createMatrix(b, rowHead2, colHead2, m, n);

    created = 1;
    printf("Both matrices created successfully!\n");
}

void displayMatrix(int x[MAX][MAX], int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            printf("%4d", x[i][j]);

        printf("\n");
    }
}

void display()
{
    if (!created)
    {
        printf("Please create matrices first!\n");
        return;
    }

    printf("\nMatrix A:\n");
    displayMatrix(a, m, n);

    printf("\nMatrix B:\n");
    displayMatrix(b, m, n);
}

void add()
{
    int i, j;

    if (!created)
    {
        printf("Please create matrices first!\n");
        return;
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            c[i][j] = a[i][j] + b[i][j];
    }

    printf("\nAddition of Matrix A and Matrix B:\n");
    displayMatrix(c, m, n);

    printf("\nNon-zero elements (row, column, value):\n");

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (c[i][j] != 0)
                printf("(%d, %d, %d)\n", i, j, c[i][j]);
        }
    }

  
    createMatrix(c, rowHead3, colHead3, m, n);
}

void main()
{
    int choice;


    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Create Two Sparse Matrices\n");
        printf("2. Display Matrices\n");
        printf("3. Add Matrices\n");
        printf("4. Exit\n");
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
                add();
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    getch();
}
