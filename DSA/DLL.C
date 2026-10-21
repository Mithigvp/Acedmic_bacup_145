#include <stdio.h>
#include <stdlib.h>

struct std
{
    int ro;
    struct std *prv, *nxt;
};

void ins(struct std **head, int no)
{
    struct std *ne, *tmp;

    ne = (struct std *)malloc(sizeof(struct std));

    ne->ro = no;

    if (*head == NULL)
    {
        ne->nxt = ne;
        ne->prv = ne;
        *head = ne;
    }
    else
    {
        tmp = (*head)->prv;   // Last node

        ne->nxt = *head;
        ne->prv = tmp;

        tmp->nxt = ne;
        (*head)->prv = ne;
    }

    printf("\n%d inserted successfully", no);
}

void dis(struct std **head)
{
    struct std *tmp;

    if (*head == NULL)
    {
        printf("\nLinked list is Empty");
        return;
    }

    tmp = *head;

    printf("\nLinked List: ");

    do
    {
        printf("%d ", tmp->ro);
        tmp = tmp->nxt;
    }
    while (tmp != *head);

    printf("\n");
}

void del(struct std **head, int no)
{
    struct std *tmp;

    if (*head == NULL)
    {
        printf("\nLinked list is Empty");
        return;
    }

    tmp = *head;

    do
    {
        if (tmp->ro == no)
        {
            /* Only one node */
            if (tmp->nxt == tmp)
            {
                *head = NULL;
            }
            else
            {
                tmp->prv->nxt = tmp->nxt;
                tmp->nxt->prv = tmp->prv;

                /* If deleting head */
                if (tmp == *head)
                {
                    *head = tmp->nxt;
                }
            }

            free(tmp);

            printf("\n%d deleted successfully", no);
            return;
        }

        tmp = tmp->nxt;

    }
    while (tmp != *head);

    printf("\n%d not found", no);
}

int main()
{
    int ch, n;
    struct std *head = NULL;

    while (1)
    {
        printf("\n\n0. Exit");
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Delete");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 0:
                exit(0);

            case 1:
                printf("Enter data: ");
                scanf("%d", &n);
                ins(&head, n);
                break;

            case 2:
                dis(&head);
                break;

            case 3:
                printf("Enter number to delete: ");
                scanf("%d", &n);
                del(&head, n);
                break;

            default:
                printf("\nInvalid choice");
        }
    }

    return 0;
}
