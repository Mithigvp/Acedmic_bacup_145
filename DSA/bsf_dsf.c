#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *adj[MAX];
int visited[MAX];
int n = 0;

/* Create graph */
void create()
{
    int i, edges, u, v;
    struct Node *newNode;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
    {
        printf("Invalid number of vertices!\n");
        n = 0;
        return;
    }

    for (i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            printf("Invalid edge! Try again.\n");
            i--;
            continue;
        }

        /* Add edge u to v */
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->vertex = v;
        newNode->next = adj[u];
        adj[u] = newNode;

        /* Add edge v to u */
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->vertex = u;
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    printf("Graph created successfully!\n");
}

/* Breadth First Search */
void BFS(int start)
{
    int queue[MAX];
    int front, rear, i, v, w;
    struct Node *temp;

    for (i = 0; i
		< n; i++)
        visited[i] = 0;

    front = 0;
    rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        temp = adj[v];

        while (temp != NULL)
        {
            w = temp->vertex;

            if (visited[w] == 0)
            {
                visited[w] = 1;
                queue[rear++] = w;
            }

            temp = temp->next;
        }
    }

    printf("\n");
}

/* Depth First Search */
void DFS(int v)
{
    struct Node *temp;
    int w;

    visited[v] = 1;
    printf("%d ", v);

    temp = adj[v];

    while (temp != NULL)
    {
        w = temp->vertex;

        if (visited[w] == 0)
            DFS(w);

        temp = temp->next;
    }
}

/* Main function */
int main()
{
    int choice, start, i;

    while (1)
    {
        printf("\n--- MENU ---\n");
        printf("1. Create Graph\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create();
                break;

            case 2:
                if (n == 0)
                {
                    printf("Please create the graph first!\n");
                    break;
                }

                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);

                if (start >= 0 && start < n)
                    BFS(start);
                else
                    printf("Invalid starting vertex!\n");

                break;

            case 3:
                if (n == 0)
                {
                    printf("Please create the graph first!\n");
                    break;
                }

                printf("Enter starting vertex (0 to %d): ", n - 1);
                scanf("%d", &start);

                if (start >= 0 && start < n)
                {
                    for (i = 0; i < n; i++)
                        visited[i] = 0;

                    printf("DFS Traversal: ");
                    DFS(start);
                    printf("\n");
                }
                else
                    printf("Invalid starting vertex!\n");

                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}