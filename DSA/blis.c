#include <stdio.h>
#include <stdlib.h>

int linearsearch(int a[], int n, int val)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (a[i] == val)
        {
            return i;
        }
    }

    return -1;
}

int binarysearch(int a[], int l, int h, int val)
{
    int m;

    while (l <= h)
    {
        m = l + (h - l) / 2;

        if (a[m] == val)
        {
            return m;
        }
        else if (a[m] < val)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }

    return -1;
}

void sortarray(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int n, i, ch, index, fval;
    int *a;

    printf("Enter No. of The Elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of elements.\n");
        return 1;
    }

    a = (int *)malloc(n * sizeof(int));

    if (a == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter %d Element value: ", i + 1);
        scanf("%d", &a[i]);
    }

    do
    {
        printf("\n===== Binary And Linear Search Menu =====\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");

        printf("Enter your Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter value To Search (Linear): ");
                scanf("%d", &fval);

                index = linearsearch(a, n, fval);

                if (index != -1)
                {
                    printf("Value Found at Index %d.\n", index);
                }
                else
                {
                    printf("Value Not Found In The Array.\n");
                }
                break;

            case 2:
                printf("Enter value To Search (Binary): ");
                scanf("%d", &fval);

                sortarray(a, n);

                index = binarysearch(a, 0, n - 1, fval);

                if (index != -1)
                {
                    printf("Value Found at Index %d (in sorted array).\n", index);
                }
                else
                {
                    printf("Value Not Found In The Array.\n");
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice, Please Try Again.\n");
        }

    } while (ch != 3);

    free(a);

    return 0;
}
