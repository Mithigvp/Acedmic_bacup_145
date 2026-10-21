#include<stdio.h>
#include<stdlib.h>

struct node 
{
	struct node *lp;
	int		data;
	struct node *rp;
}

void main()
{
	
	



}

void insert_iterative(struct node **root , int val)
{
	struct node *curr, *prev, *newnode;
	newnode =(struct node*) malloc(sizeof(struct node));
	newnode -> lp = NULL;
	newnode -> rp = NULL;
	newnode -> data = val;

	curr = *root;
	prev = NULL;

	if(*root == NULL)
	{
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

void delete_iterative(struct **root, int dval)
{
	struct node *curr, *parent;
    struct node *successor, *successor_parent;

    curr = *root;
    parent = NULL;


	 while (curr != NULL && curr->data != dval)
	 {
        parent = curr;
        if (dval < curr->data) 
		{
            curr = curr->lp;
        } else 
		{
            curr = curr->rp;
        }
    }
	
	if (curr == NULL)
    {
        printf("dval in not found");
    }

	if (curr->lp == NULL || curr->rp == NULL)
    {
        struct nodeo *child;

        if (curr->lp != NULL)
		{
            child = curr->lp;
		}
        else
		{
            child = curr->rp;
		}		

// delete root

		if (parent == NULL)
        {
            *root = child;
        }
        else if (parent->lp == curr)
        {
            parent->lp = child;
        }
        else
        {
            parent->rp = child;
        }

        free(curr);
}

void dispaly_iterative(struct **root)
{


}