#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef enum
{
	false = 0, true = 1
} bool;

struct BPlusTreeNode
{
	int *keys;
	struct BPlusTreeNode **children;
	struct BPlusTreeNode *next;
	int num_keys;
	bool is_leaf;
};

struct BPlusTree
{
	struct BPlusTreeNode *root;
	int t;
};

struct BPlusTreeNode* createNode(int t, bool is_leaf)
{
	int i;
	struct BPlusTreeNode *node = (struct BPlusTreeNode*)malloc(sizeof(struct BPlusTreeNode));
	node->is_leaf = is_leaf;
	node->num_keys = 0;
	node->next = NULL;
	node->keys = (int*)malloc(sizeof(int) * (2 * t - 1));
	node->children = (struct BPlusTreeNode**)malloc(sizeof(struct BPlusTreeNode*) * (2 * t));

	for (i = 0; i < 2 * t; i++)
	{
		node->children[i] = NULL;
	}
	return node;
}

struct BPlusTree* createBPlusTree(int t)
{
	struct BPlusTree *tree;
	if (t < 2)
	{
		printf("\n Error: Minimum degree 't' must be at least 2.\n");
		return NULL;
	}
	tree = (struct BPlusTree*)malloc(sizeof(struct BPlusTree));
	tree->t = t;
	tree->root = createNode(t, true);
	printf("\n [SYSTEM] B+ Tree created successfully with t = %d.\n", t);
	return tree;
}

int findKey(struct BPlusTreeNode *node, int key)
{
	int idx = 0;
	while (idx < node->num_keys && node->keys[idx] < key)
	{
		idx++;
	}
	return idx;
}

void splitChild(struct BPlusTreeNode *parent, int i, struct BPlusTreeNode *fullChild, int t)
{
	int j;
	struct BPlusTreeNode *newChild = createNode(t, fullChild->is_leaf);

	printf("  [SPLIT] Node is full with %d keys. Splitting...\n", fullChild->num_keys);

	if (fullChild->is_leaf)
	{
		newChild->num_keys = t;
		for (j = 0; j < t; j++)
		{
			newChild->keys[j] = fullChild->keys[j + t - 1];
		}
		fullChild->num_keys = t - 1;

		newChild->next = fullChild->next;
		fullChild->next = newChild;

		for (j = parent->num_keys; j >= i + 1; j--)
		{
			parent->children[j + 1] = parent->children[j];
		}
		parent->children[i + 1] = newChild;

		for (j = parent->num_keys - 1; j >= i; j--)
		{
			parent->keys[j + 1] = parent->keys[j];
		}

		parent->keys[i] = newChild->keys[0];
		parent->num_keys++;
	}
	else
	{
		newChild->num_keys = t - 1;
		for (j = 0; j < t - 1; j++)
		{
			newChild->keys[j] = fullChild->keys[j + t];
		}
		for (j = 0; j < t; j++)
		{
			newChild->children[j] = fullChild->children[j + t];
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
	}

	printf("  [SPLIT] Median key [%d] promoted to parent.\n", parent->keys[i]);
}

void insertNonFull(struct BPlusTreeNode *node, int key, int t)
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
			if (key >= node->keys[i])
			{
				i++;
			}
		}
		insertNonFull(node->children[i], key, t);
	}
}

void insert(struct BPlusTree *tree, int key)
{
	struct BPlusTreeNode *r;
	struct BPlusTreeNode *newRoot;
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

void merge(struct BPlusTreeNode *node, int idx, int t)
{
	int i;
	struct BPlusTreeNode *child = node->children[idx];
	struct BPlusTreeNode *sibling = node->children[idx + 1];

	if (child->is_leaf)
	{
		printf("  [MERGE] Merging leaf nodes...\n");
		for (i = 0; i < sibling->num_keys; i++)
		{
			child->keys[child->num_keys + i] = sibling->keys[i];
		}
		child->num_keys += sibling->num_keys;
		child->next = sibling->next;
	}
	else
	{
		printf("  [MERGE] Merging internal nodes with parent key [%d]...\n", node->keys[idx]);
		child->keys[t - 1] = node->keys[idx];
		for (i = 0; i < sibling->num_keys; i++)
		{
			child->keys[i + t] = sibling->keys[i];
		}
		for (i = 0; i <= sibling->num_keys; i++)
		{
			child->children[i + t] = sibling->children[i];
		}
		child->num_keys += sibling->num_keys + 1;
	}

	for (i = idx + 1; i < node->num_keys; i++)
	{
		node->keys[i - 1] = node->keys[i];
	}
	for (i = idx + 2; i <= node->num_keys; i++)
	{
		node->children[i - 1] = node->children[i];
	}
	node->num_keys--;

	free(sibling->keys);
	free(sibling->children);
	free(sibling);
}

void fill(struct BPlusTreeNode *node, int idx, int t)
{
	int i;
	struct BPlusTreeNode *child = node->children[idx];
	struct BPlusTreeNode *leftSibling = (idx != 0) ? node->children[idx - 1] : NULL;
	struct BPlusTreeNode *rightSibling = (idx != node->num_keys) ? node->children[idx + 1] : NULL;

	if (leftSibling && leftSibling->num_keys >= t)
	{
		printf("  [BORROW] Borrowing a key from left sibling...\n");
		if (child->is_leaf)
		{
			for (i = child->num_keys - 1; i >= 0; i--)
			{
				child->keys[i + 1] = child->keys[i];
			}
			child->keys[0] = leftSibling->keys[leftSibling->num_keys - 1];
			child->num_keys++;
			leftSibling->num_keys--;
			node->keys[idx - 1] = child->keys[0];
		}
		else
		{
			for (i = child->num_keys - 1; i >= 0; i--)
			{
				child->keys[i + 1] = child->keys[i];
			}
			for (i = child->num_keys; i >= 0; i--)
			{
				child->children[i + 1] = child->children[i];
			}
			child->keys[0] = node->keys[idx - 1];
			child->children[0] = leftSibling->children[leftSibling->num_keys];
			node->keys[idx - 1] = leftSibling->keys[leftSibling->num_keys - 1];
			child->num_keys++;
			leftSibling->num_keys--;
		}
	}
	else if (rightSibling && rightSibling->num_keys >= t)
	{
		printf("  [BORROW] Borrowing a key from right sibling...\n");
		if (child->is_leaf)
		{
			child->keys[child->num_keys] = rightSibling->keys[0];
			child->num_keys++;
			for (i = 1; i < rightSibling->num_keys; i++)
			{
				rightSibling->keys[i - 1] = rightSibling->keys[i];
			}
			rightSibling->num_keys--;
			node->keys[idx] = rightSibling->keys[0];
		}
		else
		{
			child->keys[child->num_keys] = node->keys[idx];
			child->children[child->num_keys + 1] = rightSibling->children[0];
			node->keys[idx] = rightSibling->keys[0];
			for (i = 1; i < rightSibling->num_keys; i++)
			{
				rightSibling->keys[i - 1] = rightSibling->keys[i];
			}
			for (i = 1; i <= rightSibling->num_keys; i++)
			{
				rightSibling->children[i - 1] = rightSibling->children[i];
			}
			child->num_keys++;
			rightSibling->num_keys--;
		}
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

void deleteFromNode(struct BPlusTreeNode *node, int key, int t)
{
	int i, idx = findKey(node, key);

	if (node->is_leaf)
	{
		if (idx < node->num_keys && node->keys[idx] == key)
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
			printf("  [NOT FOUND] Key [%d] does not exist in the B+ Tree.\n", key);
		}
		return;
	}

	if (node->children[idx]->num_keys < t)
	{
		fill(node, idx, t);
	}

	if (idx > node->num_keys)
	{
		deleteFromNode(node->children[idx - 1], key, t);
	}
	else
	{
		deleteFromNode(node->children[idx], key, t);
	}
}

void deleteKey(struct BPlusTree *tree, int key)
{
	struct BPlusTreeNode *root;

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
		struct BPlusTreeNode *tmp = root;
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

void displayLeafList(struct BPlusTreeNode *root)
{
	struct BPlusTreeNode *curr = root;
	if (curr == NULL) return;

	while (!curr->is_leaf)
	{
		curr = curr->children[0];
	}

	printf("\n Linked Leaf List: ");
	while (curr != NULL)
	{
		int i;
		printf("[ ");
		for (i = 0; i < curr->num_keys; i++)
		{
			printf("%d ", curr->keys[i]);
		}
		printf("] -> ");
		curr = curr->next;
	}
	printf("NULL\n");
}

void freeNode(struct BPlusTreeNode *node)
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

void freeBPlusTree(struct BPlusTree *tree)
{
	if (tree)
	{
		freeNode(tree->root);
		free(tree);
	}
}

void main()
{
	struct BPlusTree *bPlusTree;
	int choice, t;


	printf("==========================================\n");
	printf("      INTERACTIVE B+ TREE MANAGER        \n");
	printf("==========================================\n");
	printf("Enter minimum degree 't' (minimum 2): ");
	scanf("%d", &t);

	while (t < 2)
	{
		printf("Invalid degree! Enter t >= 2: ");
		scanf("%d", &t);
	}

	bPlusTree = createBPlusTree(t);

	while (1)
	{
		printf("\n-----------------------------\n");
		printf("Select an Option:\n");
		printf("1. Insert Key\n");
		printf("2. Delete Key\n");
		printf("3. Display Linked Leaf Sequence\n");
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
				insert(bPlusTree, key);
				break;
			}

			case 2:
			{
				int key;
				printf("Enter key to delete: ");
				scanf("%d", &key);
				deleteKey(bPlusTree, key);
				break;
			}

			case 3:
			{
				if (bPlusTree->root && bPlusTree->root->num_keys > 0)
				{
					displayLeafList(bPlusTree->root);
				}
				else
				{
					printf("\n [Empty Tree]\n");
				}
				break;
			}

			case 4:
			{
				printf("\nExiting application.\n");
				freeBPlusTree(bPlusTree);
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