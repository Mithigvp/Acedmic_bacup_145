#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef enum
{
	false = 0, true = 1
} bool;

struct BTreeNode
{
	int *keys;
	struct BTreeNode **children;
	int num_keys;
	bool is_leaf;
};

struct BTree
{
	struct BTreeNode *root;
	int t;
};

struct BTreeNode* createNode(int t, bool is_leaf)
{
	int i;
	struct BTreeNode *node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
	node->is_leaf = is_leaf;
	node->num_keys = 0;
	node->keys = (int*)malloc(sizeof(int) * (2 * t - 1));
	node->children = (struct BTreeNode**)malloc(sizeof(struct BTreeNode*) * (2 * t));

	for (i = 0; i < 2 * t; i++)
	{
		node->children[i] = NULL;
	}
	return node;
}

struct BTree* createBTree(int t)
{
	struct BTree *tree;
	if (t < 2)
	{
		printf("\n Error: Minimum degree 't' must be at least 2.\n");
		return NULL;
	}
	tree = (struct BTree*)malloc(sizeof(struct BTree));
	tree->t = t;
	tree->root = createNode(t, true);
	printf("\n [SYSTEM] B-Tree created successfully with t = %d.\n", t);
	return tree;
}

int findKey(struct BTreeNode *node, int key)
{
	int idx = 0;
	while (idx < node->num_keys && node->keys[idx] < key)
	{
		idx++;
	}
	return idx;
}

void splitChild(struct BTreeNode *parent, int i, struct BTreeNode *fullChild, int t)
{
	int j;
	struct BTreeNode *newChild = createNode(t, fullChild->is_leaf);
	newChild->num_keys = t - 1;

	printf("  [SPLIT] Node is full with %d keys. Splitting...\n", fullChild->num_keys);

	for (j = 0; j < t - 1; j++)
	{
		newChild->keys[j] = fullChild->keys[j + t];
	}

	if (!fullChild->is_leaf)
	{
		for (j = 0; j < t; j++)
		{
			newChild->children[j] = fullChild->children[j + t];
		}
	}

	fullChild->num_keys = t - 1;

	for (j = parent->num_keys; j >= i + 1; j--)
	{
		parent->children[j + 1] = parent->children[j];
	}
	parent->children[i + 1] = newChild;

	for (j = parent->num_keys - 1; j >= i; j--)
	{
		parent->keys[j + 1] = parent->keys[j];
	}

	parent->keys[i] = fullChild->keys[t - 1];
	parent->num_keys++;

	printf("  [SPLIT] Median key [%d] promoted to parent.\n", parent->keys[i]);
}

void insertNonFull(struct BTreeNode *node, int key, int t)
{
	int i = node->num_keys - 1;

	if (node->is_leaf)
	{
		while (i >= 0 && key < node->keys[i])
		{
			node->keys[i + 1] = node->keys[i];
			i--;
		}
		node->keys[i + 1] = key;
		node->num_keys++;
		printf("  [INSERT] Key [%d] inserted into leaf node successfully.\n", key);
	}
	else
	{
		while (i >= 0 && key < node->keys[i])
		{
			i--;
		}
		i++;

		if (node->children[i]->num_keys == (2 * t - 1))
		{
			splitChild(node, i, node->children[i], t);
			if (key > node->keys[i])
			{
				i++;
			}
		}
		insertNonFull(node->children[i], key, t);
	}
}

void insert(struct BTree *tree, int key)
{
	struct BTreeNode *r;
	struct BTreeNode *newRoot;
	int t;

	if (!tree || !tree->root) return;

	r = tree->root;
	t = tree->t;

	printf("\n --- INSERTION: Key [%d] ---\n", key);

	if (r->num_keys == (2 * t - 1))
	{
		printf("  [ROOT FULL] Splitting root node and increasing tree height...\n");
		newRoot = createNode(t, false);
		tree->root = newRoot;
		newRoot->children[0] = r;
		splitChild(newRoot, 0, r, t);
		insertNonFull(newRoot, key, t);
	}
	else
	{
		insertNonFull(r, key, t);
	}
}

int getPredecessor(struct BTreeNode *node)
{
	struct BTreeNode *curr = node;
	while (!curr->is_leaf)
	{
		curr = curr->children[curr->num_keys];
	}
	return curr->keys[curr->num_keys - 1];
}

int getSuccessor(struct BTreeNode *node)
{
	struct BTreeNode *curr = node;
	while (!curr->is_leaf)
	{
		curr = curr->children[0];
	}
	return curr->keys[0];
}

void merge(struct BTreeNode *node, int idx, int t)
{
	int i;
	struct BTreeNode *child = node->children[idx];
	struct BTreeNode *sibling = node->children[idx + 1];

	printf("  [MERGE] Merging key [%d] from parent into child nodes...\n", node->keys[idx]);

	child->keys[t - 1] = node->keys[idx];

	for (i = 0; i < sibling->num_keys; i++)
	{
		child->keys[i + t] = sibling->keys[i];
	}

	if (!child->is_leaf)
	{
		for (i = 0; i <= sibling->num_keys; i++)
		{
			child->children[i + t] = sibling->children[i];
		}
	}

	for (i = idx + 1; i < node->num_keys; i++)
	{
		node->keys[i - 1] = node->keys[i];
	}

	for (i = idx + 2; i <= node->num_keys; i++)
	{
		node->children[i - 1] = node->children[i];
	}

	child->num_keys += sibling->num_keys + 1;
	node->num_keys--;

	free(sibling->keys);
	free(sibling->children);
	free(sibling);
}

void fill(struct BTreeNode *node, int idx, int t)
{
	int i;
	struct BTreeNode *child = node->children[idx];
	struct BTreeNode *leftSibling = (idx != 0) ? node->children[idx - 1] : NULL;
	struct BTreeNode *rightSibling = (idx != node->num_keys) ? node->children[idx + 1] : NULL;

	if (leftSibling && leftSibling->num_keys >= t)
	{
		printf("  [BORROW] Borrowing a key from left sibling...\n");
		for (i = child->num_keys - 1; i >= 0; i--)
		{
			child->keys[i + 1] = child->keys[i];
		}

		if (!child->is_leaf)
		{
			for (i = child->num_keys; i >= 0; i--)
			{
				child->children[i + 1] = child->children[i];
			}
		}

		child->keys[0] = node->keys[idx - 1];

		if (!child->is_leaf)
		{
			child->children[0] = leftSibling->children[leftSibling->num_keys];
		}

		node->keys[idx - 1] = leftSibling->keys[leftSibling->num_keys - 1];
		child->num_keys++;
		leftSibling->num_keys--;
	}
	else if (rightSibling && rightSibling->num_keys >= t)
	{
		printf("  [BORROW] Borrowing a key from right sibling...\n");
		child->keys[child->num_keys] = node->keys[idx];

		if (!child->is_leaf)
		{
			child->children[child->num_keys + 1] = rightSibling->children[0];
		}

		node->keys[idx] = rightSibling->keys[0];

		for (i = 1; i < rightSibling->num_keys; i++)
		{
			rightSibling->keys[i - 1] = rightSibling->keys[i];
		}

		if (!rightSibling->is_leaf)
		{
			for (i = 1; i <= rightSibling->num_keys; i++)
			{
				rightSibling->children[i - 1] = rightSibling->children[i];
			}
		}

		child->num_keys++;
		rightSibling->num_keys--;
	}
	else
	{
		if (idx != node->num_keys)
		{
			merge(node, idx, t);
		}
		else
		{
			merge(node, idx - 1, t);
		}
	}
}

void deleteFromNode(struct BTreeNode *node, int key, int t)
{
	int i, idx = findKey(node, key);
	bool flag;

	if (idx < node->num_keys && node->keys[idx] == key)
	{
		if (node->is_leaf)
		{
			for (i = idx + 1; i < node->num_keys; i++)
			{
				node->keys[i - 1] = node->keys[i];
			}
			node->num_keys--;
			printf("  [DELETE] Key [%d] deleted from leaf node.\n", key);
		}
		else
		{
			if (node->children[idx]->num_keys >= t)
			{
				int pred = getPredecessor(node->children[idx]);
				printf("  [DELETE] Key [%d] is in internal node. Replacing with predecessor [%d]...\n", key, pred);
				node->keys[idx] = pred;
				deleteFromNode(node->children[idx], pred, t);
			}
			else if (node->children[idx + 1]->num_keys >= t)
			{
				int succ = getSuccessor(node->children[idx + 1]);
				printf("  [DELETE] Key [%d] is in internal node. Replacing with successor [%d]...\n", key, succ);
				node->keys[idx] = succ;
				deleteFromNode(node->children[idx + 1], succ, t);
			}
			else
			{
				merge(node, idx, t);
				deleteFromNode(node->children[idx], key, t);
			}
		}
	}
	else
	{
		if (node->is_leaf)
		{
			printf("  [NOT FOUND] Key [%d] does not exist in the B-Tree.\n", key);
			return;
		}

		flag = (idx == node->num_keys);

		if (node->children[idx]->num_keys < t)
		{
			fill(node, idx, t);
		}

		if (flag && idx > node->num_keys)
		{
			deleteFromNode(node->children[idx - 1], key, t);
		}
		else
		{
			deleteFromNode(node->children[idx], key, t);
		}
	}
}

void deleteKey(struct BTree *tree, int key)
{
	struct BTreeNode *root;

	if (!tree || !tree->root)
	{
		printf("\n [ERROR] Tree is empty.\n");
		return;
	}

	printf("\n --- DELETION: Key [%d] ---\n", key);

	root = tree->root;
	deleteFromNode(root, key, tree->t);

	if (root->num_keys == 0)
	{
		struct BTreeNode *tmp = root;
		if (root->is_leaf)
		{
			tree->root = NULL;
		}
		else
		{
			tree->root = root->children[0];
		}
		free(tmp->keys);
		free(tmp->children);
		free(tmp);
		printf("  [ROOT UPDATED] Tree height reduced.\n");
	}
}

void traverse(struct BTreeNode *root)
{
	int i;
	if (root == NULL) return;

	for (i = 0; i < root->num_keys; i++)
	{
		if (!root->is_leaf)
		{
			traverse(root->children[i]);
		}
		printf("%d ", root->keys[i]);
	}

	if (!root->is_leaf)
	{
		traverse(root->children[i]);
	}
}

void freeNode(struct BTreeNode *node)
{
	int i;
	if (node == NULL) return;
	if (!node->is_leaf)
	{
		for (i = 0; i <= node->num_keys; i++)
		{
			freeNode(node->children[i]);
		}
	}
	free(node->keys);
	free(node->children);
	free(node);
}

void freeBTree(struct BTree *tree)
{
	if (tree)
	{
		freeNode(tree->root);
		free(tree);
	}
}

void main()
{
	struct BTree *bTree;
	int choice, t;


	printf("==========================================\n");
	printf("       INTERACTIVE B-TREE MANAGER        \n");
	printf("==========================================\n");
	printf("Enter minimum degree 't' (minimum 2): ");
	scanf("%d", &t);

	while (t < 2)
	{
		printf("Invalid degree! Enter t >= 2: ");
		scanf("%d", &t);
	}

	bTree = createBTree(t);

	while (1)
	{
		printf("\n-----------------------------\n");
		printf("Select an Option:\n");
		printf("1. Insert Key\n");
		printf("2. Delete Key\n");
		printf("3. Traverse / Print Tree\n");
		printf("4. Exit\n");
		printf("-----------------------------\n");
		printf("Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
			case 1:
			{
				int key;
				printf("Enter key to insert: ");
				scanf("%d", &key);
				insert(bTree, key);
				break;
			}

			case 2:
			{
				int key;
				printf("Enter key to delete: ");
				scanf("%d", &key);
				deleteKey(bTree, key);
				break;
			}

			case 3:
			{
				printf("\nIn-order Traversal of B-Tree: ");
				if (bTree->root && bTree->root->num_keys > 0)
				{
					traverse(bTree->root);
				}
				else
				{
					printf("[Empty Tree]");
				}
				printf("\n");
				break;
			}

			case 4:
			{
				printf("\nExiting application.\n");
				freeBTree(bTree);
				exit(0);
			}

			default:
			{
				printf("Invalid choice! Please select between 1 and 4.\n");
				break;
			}
		}
	}
}