#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef enum
{
	RED = 0, BLACK = 1
} Color;

typedef struct RBNode
{
	int data;
	Color color;
	struct RBNode *left;
	struct RBNode *right;
	struct RBNode *parent;
} RBNode;

typedef struct RBTree
{
	RBNode *root;
	RBNode *NIL;
} RBTree;

/* Forward Declarations for C89 */
void leftRotate(RBTree *tree, RBNode *x);
void rightRotate(RBTree *tree, RBNode *x);

RBNode* createNode(RBTree *tree, int data)
{
	RBNode *node = (RBNode*)malloc(sizeof(RBNode));
	node->data = data;
	node->color = RED;
	node->left = tree->NIL;
	node->right = tree->NIL;
	node->parent = tree->NIL;
	return node;
}

RBTree* createRBTree()
{
	RBTree *tree = (RBTree*)malloc(sizeof(RBTree));
	tree->NIL = (RBNode*)malloc(sizeof(RBNode));
	tree->NIL->color = BLACK;
	tree->NIL->left = NULL;
	tree->NIL->right = NULL;
	tree->NIL->parent = NULL;
	tree->NIL->data = 0;
	tree->root = tree->NIL;
	printf("\n [SYSTEM] Red-Black Tree initialized.\n");
	return tree;
}

void leftRotate(RBTree *tree, RBNode *x)
{
	RBNode *y = x->right;
	x->right = y->left;

	if (y->left != tree->NIL)
	{
		y->left->parent = x;
	}

	y->parent = x->parent;

	if (x->parent == tree->NIL)
	{
		tree->root = y;
	}
	else if (x == x->parent->left)
	{
		x->parent->left = y;
	}
	else
	{
		x->parent->right = y;
	}

	y->left = x;
	x->parent = y;
	printf("  [ROTATE] Left rotation performed on node [%d].\n", x->data);
}

void rightRotate(RBTree *tree, RBNode *x)
{
	RBNode *y = x->left;
	x->left = y->right;

	if (y->right != tree->NIL)
	{
		y->right->parent = x;
	}

	y->parent = x->parent;

	if (x->parent == tree->NIL)
	{
		tree->root = y;
	}
	else if (x == x->parent->right)
	{
		x->parent->right = y;
	}
	else
	{
		x->parent->left = y;
	}

	y->right = x;
	x->parent = y;
	printf("  [ROTATE] Right rotation performed on node [%d].\n", x->data);
}

void fixInsert(RBTree *tree, RBNode *k)
{
	RBNode *u;

	while (k->parent->color == RED)
	{
		if (k->parent == k->parent->parent->right)
		{
			u = k->parent->parent->left;
			if (u->color == RED)
			{
				u->color = BLACK;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				k = k->parent->parent;
				printf("  [RECOLOR] Recoloring parent and uncle nodes.\n");
			}
			else
			{
				if (k == k->parent->left)
				{
					k = k->parent;
					rightRotate(tree, k);
				}
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				leftRotate(tree, k->parent->parent);
			}
		}
		else
		{
			u = k->parent->parent->right;
			if (u->color == RED)
			{
				u->color = BLACK;
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				k = k->parent->parent;
				printf("  [RECOLOR] Recoloring parent and uncle nodes.\n");
			}
			else
			{
				if (k == k->parent->right)
				{
					k = k->parent;
					leftRotate(tree, k);
				}
				k->parent->color = BLACK;
				k->parent->parent->color = RED;
				rightRotate(tree, k->parent->parent);
			}
		}

		if (k == tree->root)
		{
			break;
		}
	}
	tree->root->color = BLACK;
}

void insert(RBTree *tree, int key)
{
	RBNode *node;
	RBNode *y;
	RBNode *x;

	node = createNode(tree, key);
	y = tree->NIL;
	x = tree->root;

	printf("\n --- INSERTION: Key [%d] ---\n", key);

	while (x != tree->NIL)
	{
		y = x;
		if (node->data < x->data)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	node->parent = y;

	if (y == tree->NIL)
	{
		tree->root = node;
	}
	else if (node->data < y->data)
	{
		y->left = node;
	}
	else
	{
		y->right = node;
	}

	printf("  [INSERT] Node [%d] added to tree as RED.\n", key);

	if (node->parent == tree->NIL)
	{
		node->color = BLACK;
		return;
	}

	if (node->parent->parent == tree->NIL)
	{
		return;
	}

	fixInsert(tree, node);
}

void fixDelete(RBTree *tree, RBNode *x)
{
	RBNode *s;

	while (x != tree->root && x->color == BLACK)
	{
		if (x == x->parent->left)
		{
			s = x->parent->right;
			if (s->color == RED)
			{
				s->color = BLACK;
				x->parent->color = RED;
				leftRotate(tree, x->parent);
				s = x->parent->right;
			}

			if (s->left->color == BLACK && s->right->color == BLACK)
			{
				s->color = RED;
				x = x->parent;
			}
			else
			{
				if (s->right->color == BLACK)
				{
					s->left->color = BLACK;
					s->color = RED;
					rightRotate(tree, s);
					s = x->parent->right;
				}

				s->color = x->parent->color;
				x->parent->color = BLACK;
				s->right->color = BLACK;
				leftRotate(tree, x->parent);
				x = tree->root;
			}
		}
		else
		{
			s = x->parent->left;
			if (s->color == RED)
			{
				s->color = BLACK;
				x->parent->color = RED;
				rightRotate(tree, x->parent);
				s = x->parent->left;
			}

			if (s->right->color == BLACK && s->left->color == BLACK)
			{
				s->color = RED;
				x = x->parent;
			}
			else
			{
				if (s->left->color == BLACK)
				{
					s->right->color = BLACK;
					s->color = RED;
					leftRotate(tree, s);
					s = x->parent->left;
				}

				s->color = x->parent->color;
				x->parent->color = BLACK;
				s->left->color = BLACK;
				rightRotate(tree, x->parent);
				x = tree->root;
			}
		}
	}
	x->color = BLACK;
}

void rbTransplant(RBTree *tree, RBNode *u, RBNode *v)
{
	if (u->parent == tree->NIL)
	{
		tree->root = v;
	}
	else if (u == u->parent->left)
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}
	v->parent = u->parent;
}

RBNode* minimum(RBTree *tree, RBNode *node)
{
	while (node->left != tree->NIL)
	{
		node = node->left;
	}
	return node;
}

void deleteNodeHelper(RBTree *tree, RBNode *z)
{
	RBNode *x;
	RBNode *y;
	Color yOriginalColor;

	y = z;
	yOriginalColor = y->color;

	if (z->left == tree->NIL)
	{
		x = z->right;
		rbTransplant(tree, z, z->right);
	}
	else if (z->right == tree->NIL)
	{
		x = z->left;
		rbTransplant(tree, z, z->left);
	}
	else
	{
		y = minimum(tree, z->right);
		yOriginalColor = y->color;
		x = y->right;

		if (y->parent == z)
		{
			x->parent = y;
		}
		else
		{
			rbTransplant(tree, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}

		rbTransplant(tree, z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}

	free(z);

	if (yOriginalColor == BLACK)
	{
		fixDelete(tree, x);
	}
}

void deleteKey(RBTree *tree, int data)
{
	RBNode *z = tree->root;

	if (tree->root == tree->NIL)
	{
		printf("\n [ERROR] Tree is empty.\n");
		return;
	}

	printf("\n --- DELETION: Key [%d] ---\n", data);

	while (z != tree->NIL && z->data != data)
	{
		if (data < z->data)
		{
			z = z->left;
		}
		else
		{
			z = z->right;
		}
	}

	if (z == tree->NIL)
	{
		printf("  [NOT FOUND] Key [%d] does not exist in Red-Black Tree.\n", data);
		return;
	}

	deleteNodeHelper(tree, z);
	printf("  [DELETE] Node [%d] deleted successfully.\n", data);
}

void inorder(RBTree *tree, RBNode *root)
{
	if (root != tree->NIL)
	{
		inorder(tree, root->left);
		printf("%d(%s) ", root->data, root->color == RED ? "R" : "B");
		inorder(tree, root->right);
	}
}

void freeNodes(RBTree *tree, RBNode *node)
{
	if (node != tree->NIL)
	{
		freeNodes(tree, node->left);
		freeNodes(tree, node->right);
		free(node);
	}
}

void freeRBTree(RBTree *tree)
{
	if (tree)
	{
		freeNodes(tree, tree->root);
		free(tree->NIL);
		free(tree);
	}
}

void main()
{
	RBTree *tree;
	int choice;
	int key;


	printf("   INTERACTIVE RED-BLACK TREE MANAGER    \n");
	
	tree = createRBTree();

	while (1)
	{
		printf("\n-----------------------------\n");
		printf("Select an Option:\n");
		printf("1. Insert Key\n");
		printf("2. Delete Key\n");
		printf("3. Display In-order Traversal\n");
		printf("4. Exit\n");
		printf("-----------------------------\n");
		printf("Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
				printf("Enter key to insert: ");
				scanf("%d", &key);
				insert(tree, key);
				break;

			case 2:
				printf("Enter key to delete: ");
				scanf("%d", &key);
				deleteKey(tree, key);
				break;

			case 3:
				printf("\nIn-order Traversal [Value(Color)]: ");
				if (tree->root != tree->NIL)
				{
					inorder(tree, tree->root);
				}
				else
				{
					printf("[Empty Tree]");
				}
				printf("\n");
				break;

			case 4:
				printf("\nExiting application.\n");
				freeRBTree(tree);
				exit(0);

			default:
				printf("Invalid choice! Please select between 1 and 4.\n");
				break;
		}
	}
}