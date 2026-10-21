#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct std{
	int rl;
	struct std *nxt;
};
void ins(struct std **head,int n)
{
	struct std * ne,*tmp;
	tmp=*head;
	if(*head == NULL)
	{
		*head=(struct std*) malloc(sizeof(struct std));
		(*head)->rl=n;
		(*head)->nxt=*head;
	}
	else
	{
		ne=(struct std*)malloc(sizeof(struct std));
		while(tmp->nxt!=*head)
		{
			tmp=tmp->nxt;
		}
		ne->rl=n;
		ne->nxt=tmp->nxt;
		tmp->nxt=ne;
	}
}
void dis(struct std **head)
{
	struct std * tmp;
	tmp = *head;
	do
	{
		printf(" %d ",tmp->rl);
		tmp=tmp->nxt;
	}while(tmp != *head);
}
void del(struct std **head,int n)
{
	struct std *tmp,*te;
	tmp = *head;
	te = *head;
	if((*head) -> rl == n)
	{
		while(te->nxt != *head)
		{
			te=te->nxt;
		}
		*head=(*head)->nxt;
		free(tmp);
		te->nxt=(*head);
	}
	else
	{
		while(tmp->nxt  != *head)
		{
			te=tmp;
			tmp=tmp->nxt;
			if(tmp->rl == n)
			{
				if(tmp->nxt == *head)
				{
					te->nxt=(*head);
					free(tmp);
				}
				else
				{
					te->nxt=tmp->nxt;
					free(tmp);
				}
			}
		}
	}
}
void main()
{
	int no,ch;
	struct std *head = NULL;
	while(1)
	{
		printf("\n---- singel Circular linklist ----\n");
		printf("\n 0.Exit  ");
		printf("\n 1.Insert ");
		printf("\n 2.Display ");
		printf("\n 3.Delete ");

		printf("Enter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 0:
				exit(0);
			case 1:
				printf("Enter a roll no :");
				scanf("%d",&no);
				ins(&head,no);
				break;
			case 2:
				dis(&head);
				break;
			case 3:
				printf("Enter a roll no you want to delet :");
				scanf("%d",&no);
				del(&head,no);
				break;
		}
	}
}