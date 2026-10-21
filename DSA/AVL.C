#include <stdio.h>
#include <stdlib.h>


struct node
{
	struct node *left;
	int data;
	struct node *right;
};
// height
int height(struct node *root)
{
	int hl, hr;

	if (root == NULL)
		return 0;

	hl = height(root->left);
	hr = height(root->right);

	return (hl > hr ? hl : hr) + 1;
}

//  balance factor
int balance_factor(struct node *root)
{
	if (root == NULL)
		return 0;

	return height(root->left) - height(root->right);
}

// LL Rotation
void LL_Rotation(struct node **root)
{
	struct node *pre = *root;
	struct node *curr = pre->left;

	printf("\n[ROTATION] LL (Single Right) performed on node %d", pre->data);

	pre->left = curr->right;
	curr->right = pre;

	*root = curr;
}

// RR Rotation
void RR_Rotation(struct node **root)
{
	struct node *pre = *root;
	struct node *curr = pre->right;

	printf("\n[ROTATION] RR (Single Left) performed on node %d", pre->data);
	
	pre->right = curr->left;
	curr->left = pre;

	*root = curr;
}

// LR Rotation
void LR_Rotation(struct node **root)
{
	struct node *pre = *root;
	printf("\n[ROTATION] LR Double Rotation initiated on node %d", pre->data);
	RR_Rotation(&(pre->left));
	LL_Rotation(root);
}

// RL Rotation
void RL_Rotation(struct node **root)
{
	struct node *pre = *root;
	printf("\n[ROTATION] RL Double Rotation initiated on node %d", pre->data);
	LL_Rotation(&(pre->right));
	RR_Rotation(root);
}

// balance node
void balance_node(struct node **node_ref)
{
	int bf;

	if (*node_ref == NULL)
		return;

	bf = balance_factor(*node_ref);

	if (bf > 1) 
	{
		if (balance_factor((*node_ref)->left) >= 0)
		{
			LL_Rotation(node_ref);
		}
		else
		{
			LR_Rotation(node_ref);
		}
	}	
	else if (bf < -1) 
	{
		if (balance_factor((*node_ref)->right) <= 0)
		{
			 RR_Rotation(node_ref);
		}
		else
		{
			RL_Rotation(node_ref);
		}
	}
}

// insert
void insert(struct node **root, int val)
{
	struct node *new_node, *curr, *pre;
	struct node **path[100];
	int top = -1;

	new_node = (struct node *)malloc(sizeof(struct node));
	if (new_node == NULL)
	{
		printf("\nMemory allocation failed!");
		return;
	}
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->data = val;

	curr = *root;

	if (curr == NULL)
	{
		*root = new_node;
		printf("\nRoot Node [%d] Inserted successfully.", val);
		return;
	}

 // Traversing down to up
	path[++top] = root;
	while (curr != NULL)
	{
		pre = curr;
		if (val < curr->data)
		{
			curr = curr->left;
			path[++top] = &(pre->left);
		}
		else if (val > curr->data)
		{
			curr = curr->right;
			path[++top] = &(pre->right);
		}
		else
		{
			printf("\nDuplicate key [%d] ignored.", val);
			free(new_node);
			return;
		}
	}

	*(path[top]) = new_node;
	printf("\nNode [%d] Inserted successfully.", val);

	// Backtracking up to restore
	while (top >= 0)
	{
		struct node **node_ptr = path[top--];
		balance_node(node_ptr);
	}
}



// delete
void delete_node(struct node **root, int val)
{
	struct node **path[100];
	int top = -1;
	struct node **curr_ref = root;
	struct node *curr = *root;

 // Locate target node
	while (curr != NULL && curr->data != val)
	{
		path[++top] = curr_ref;
		if (val < curr->data)
		{
			 curr_ref = &(curr->left);
		}
		else
		{
			curr_ref = &(curr->right);
		}
		curr = *curr_ref;
	}

	if (curr == NULL)
	{
		printf("\nNode [%d] Not Found in Tree!", val);
		return;
	}

	path[++top] = curr_ref;

	// Case 1: Node with 0 or 1 child
	if (curr->left == NULL || curr->right == NULL)
	{
		struct node *temp = curr->left ? curr->left : curr->right;
		*curr_ref = temp;
		free(curr);
		top--;
	}
	// Case 2: Node with 2 children 
	else
	{
		struct node **succ_ref = &(curr->right);
		struct node *succ = curr->right;
		int succ_top = top;

		path[++succ_top] = succ_ref;

		while (succ->left != NULL)
		{
			succ_ref = &(succ->left);
			succ = succ->left;
			path[++succ_top] = succ_ref;
		}

		curr->data = succ->data;
		*succ_ref = succ->right;
		free(succ);

		top = succ_top - 1;
	}

	printf("\nNode [%d] Deleted Successfully.", val);

 // restore AVL balance
	while (top >= 0)
	{
		struct node **node_ptr = path[top--];
		balance_node(node_ptr);
	}
}


//inorder

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}	
}


// Preorder

void preorder(struct node *root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


//main

void main()
{
	struct node *root = NULL;
	int ch, val;


	while (1)
	{
	
		printf("\n AVL TREE OPERATIONS ");
		
		printf("\n1. Insert Node");
		printf("\n2. Delete Node");
		printf("\n3. Display Inorder");
		printf("\n4. Display Preorder");
		printf("\n5. Root Details & Balance Factor");
		printf("\n6. Exit");
		
		printf("\nEnter your choice: ");
		scanf("%d", &ch);

		switch (ch)
		{
			case 1:
				printf("\nEnter value to insert: ");
				scanf("%d", &val);
				insert(&root, val);
				break;

			case 2:
				if (root == NULL)
				{
					printf("\nTree is empty! Nothing to delete.");
				}
				else
				{
					printf("\nEnter value to delete: ");
					scanf("%d", &val);
					delete_node(&root, val);
				}
				break;

			case 3:
				if (root == NULL)
				{
					printf("\nTree is empty!");
				}
				else
				{
					printf("\nInorder Traversal: ");
					inorder(root);
				}
				break;

			case 4:
				if (root == NULL)
				{
					printf("\nTree is empty!");
				}
				else
				{
					printf("\nPreorder Traversal: ");
					preorder(root);
				}
				break;

			case 5:
				if (root == NULL)
				{
					printf("\nTree is empty!");
				}
				else
				{
					printf("\nRoot Node Data = %d", root->data);
					printf("\nHeight Of Left Subtree = %d", height(root->left));
					printf("\nHeight Of Right Subtree = %d", height(root->right));
					printf("\nBalance Factor Of Root = %d", balance_factor(root));
				}
				break;

			case 6:
				printf("\nExiting program...");
				
				exit(0);

			default:
				printf("\nInvalid Choice! Please try again.");
		}
	}
}
