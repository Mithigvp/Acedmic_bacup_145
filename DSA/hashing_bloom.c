
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

int *bloom = NULL;
int m = SIZE;

/* First hash function */
int hash1(int key)
{
    return (key % m + m) % m;
}

/* Second hash function */
int hash2(int key)
{
    return (hash1(key) + 1) % m;
}

/* Allocate memory */
void allocation()
{
    if (bloom != NULL)
    {
        printf("Bloom Filter is already allocated.\n");
        return;
    }

    bloom = (int *)calloc(m, sizeof(int));

    if (bloom == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Bloom Filter allocated successfully.\n");
}

/* Deallocate memory */
void deallocation()
{
    if (bloom == NULL)
    {
        printf("Bloom Filter is not allocated.\n");
        return;
    }

    free(bloom);
    bloom = NULL;

    printf("Bloom Filter deallocated successfully.\n");
}

/* Insert an element */
void insert(int key)
{
    int h1, h2;

    if (bloom == NULL)
    {
        printf("Please allocate memory first.\n");
        return;
    }

    h1 = hash1(key);
    h2 = hash2(key);

    bloom[h1] = 1;
    bloom[h2] = 1;

    printf("%d inserted into Bloom Filter.\n", key);
}



/* Display bit array */
void display()
{
    int i;

    if (bloom == NULL)
    {
        printf("Please allocate memory first.\n");
        return;
    }

    printf("Bloom Filter bit array:\n");

    for (i = 0; i < m; i++)
    {
        printf("%d ", bloom[i]);

        if ((i + 1) % 20 == 0)
            printf("\n");
    }

    printf("\n");
}

int main()
{
    int choice, key;

    do
    {
        printf("\n===== BLOOM FILTER MENU =====\n");
        printf("1. Allocation\n");
        printf("2. Deallocation\n");
        printf("3. Insert Element\n");
        printf("4. Display Bloom Filter\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Exiting.\n");
            deallocation();
            return 1;
        }

        switch (choice)
        {
            case 1:
                allocation();
                break;

            case 2:
                deallocation();
                break;

            case 3:
                printf("Enter element to insert: ");
                if (scanf("%d", &key) == 1)
                    insert(key);
                else
                {
                    printf("Invalid input.\n");
                    return 1;
                }
                break;

            case 4:
                display();
                break;

            case 5:
                deallocation();
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
