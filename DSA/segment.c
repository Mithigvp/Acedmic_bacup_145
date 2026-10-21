#include <stdio.h>

#define MAX 100

int arr[MAX];
int tree[4 * MAX];
int n;

void build(int node, int start, int end)
{
    int mid;

    if (start == end)
    {
        tree[node] = arr[start];
        return;
    }

    mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void insert(int node, int start, int end,
            int index, int value)
{
    int mid;

    if (start == end)
    {
        arr[index] = value;
        tree[node] = value;
        return;
    }

    mid = (start + end) / 2;

    if (index <= mid)
    {
        insert(2 * node, start, mid, index, value);
    }
    else
    {
        insert(2 * node + 1, mid + 1, end, index, value);
    }

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}


void deleteElement(int node, int start, int end, int index)
{
    insert(node, start, end, index, 0);
}

void display(int node, int start, int end)
{
    int mid;

    printf("Node %d [%d-%d] = %d\n",
           node, start, end, tree[node]);

    if (start == end)
    {
        return;
    }

    mid = (start + end) / 2;

    display(2 * node, start, mid);
    display(2 * node + 1, mid + 1, end);
}


int main(void)
{
    int i, choice, index, value;

    printf("Enter number of elements : ", MAX);
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of elements!\n");
        return 1;
    }

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    
    build(1, 0, n - 1);

    do
    {
        printf("\n===== SEGMENT TREE MENU =====\n");
        printf("1. Insert\n");
        printf("2. Delete Element\n");
        printf("3. Display Segment Tree\n");
		printf("4. Display Array\n");
        printf("5 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value: ");
                  scanf("%d %d", &index, &value);

                if (index >= 0 && index < n)
                {
                    insert(1, 0, n - 1, index, value);
                    printf("Element updated successfully!\n");
                }
                else
                {
                    printf("Invalid index!\n");
                }
                break;

            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);

                if (index >= 0 && index < n)
                {
                    deleteElement(1, 0, n - 1, index);
                    printf("Element deleted successfully!\n");
                }
                else
                {
                    printf("Invalid index!\n");
                }
                break;

            case 3:
                printf("\nSegment Tree:\n");
                display(1, 0, n - 1);
                break;

			
            case 4:
                printf("\nArray Elements:\n");

                for (i = 0; i < n; i++)
                {
                    printf("Index %d = %d\n", i, arr[i]);
                }
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

}