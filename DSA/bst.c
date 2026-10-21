#include <stdio.h>
#include <stdlib.h>


struct node 
{
	struct node *lp;
	int		data;
	struct node *rp;
};

void main()
{
	void insert(struct node ** , int);
	void search_bts(struct node ** , int );
	void in_oder(struct node **);
	void pre_oder(struct node **);
	void post_oder(struct node **);

	int no ,ch;
	struct node *root = NULL;

	do
	{
		printf("\n=== binary search tree === \n");
		printf(" 1: insert ::\n");
		printf(" 2: search element ::\n");
		printf(" 3: in_oder display :: \n");
		printf(" 4: pre_oder display :: \n");
		printf(" 5: post_oder display:: \n");
		printf(" 6: exit\n");

		printf(" select your choice ::");
		scanf("%d", &ch);

		switch(ch)
		{
			case 1:
				printf("enter your value ::");
				scanf("%d",&no);
				insert(&root,no);
				break;

			case 2: 
				printf("enter your value ::");
				scanf("%d",&no);
				search_bts(&root , no);
				break;

			case 3: 
				in_oder(&root);
				break;

			case 4: 
				pre_oder(&root);
				break;

			case 5: 
				post_oder(&root);
				break;
				
			case 6:
				printf("exit");
				break;

			default:
				printf("invalid choice ");
				break;
		}
	}while(ch != 6);
	printf("\n");
}

void insert(struct node **root , int val)
{
	struct node *curr, *prev , *newnode;
	newnode = (struct node *) malloc(sizeof(struct node));
	newnode -> lp = NULL;
	newnode -> rp = NULL;
	newnode -> data = val;

	curr = *root;
	prev = NULL;

	if(*root == NULL){
		*root = newnode;
	}
	else
	{
		while(curr != NULL)
		{
			prev = curr;
			if(val < curr->data)
			{
				curr = curr->lp;
			}
			else
			{
				curr = curr->rp;
			}
		}

	
		if(val <  prev->data)
		{
			prev -> lp = newnode;
		}
		else
		{
			prev -> rp = newnode;	

		}
	}
	
}

void search_bts(struct node **root , int ele)
{
	struct node *curr;
	int found = 0;

	curr = *root;

	if(curr == NULL)
	{
		printf("tree is empty");
	}
	else
	{
		while(curr != NULL && !found)
		{
			if(curr -> data == ele)
			{
				found = 1;
				break;
			}
			else
			{
				if(curr -> data > ele)
				{
					curr = curr -> lp;
				}
				else
				{
					curr = curr -> rp;
				}
			}
		}
		if(found==1){
			printf("element found ");
		}
		else
		{
			printf("element not found");
		}
	}
}



void in_oder( struct node **root)
{
	struct node *curr;
	curr = *root;
	if(curr != NULL)
	{
		in_oder(&curr -> lp);
		printf("\t %d", curr -> data);
		in_oder(&curr -> rp);
	}
}



void pre_oder( struct node **root)
{
	struct node *curr;
	curr = *root;
	if(curr != NULL)
	{
		printf("\t %d", curr -> data);
		pre_oder(&curr -> lp);
		pre_oder(&curr -> rp);
	}
}


void post_oder( struct node **root)
{
	struct node *curr;
	curr = *root;
	if(curr != NULL)
	{
	
		post_oder(&curr -> lp);
		post_oder(&curr -> rp);
		printf("\t %d", curr -> data);
	}
}
