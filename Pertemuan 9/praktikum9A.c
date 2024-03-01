#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	int height;
};

int height(struct Node* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// Hitung Balance factor untuk node N
int getBalanceFactor(struct Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

struct Node* newNode(int new_data)
{
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->height = 1; // new node is initially added at leaf
	return(new_node);
}

struct Node* rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	// Lakukan rotasi
	x->right = y;
	y->left = T2;

	// Update height
	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	// Return root baru
	return x;
}


struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	// Lakukan rotasi
	y->left = x;
	x->right = T2;

	// Update height
	x->height = max(height(x->left), height(x->right))+1;
	y->height = max(height(y->left), height(y->right))+1;

	// Return root baru
	return y;
}

struct Node* insert(struct Node* node, int new_data)
{
	// 1. Lakukan BST insert biasa
	if (node == NULL)
		return(newNode(new_data));

	if (new_data < node->data)
		node->left = insert(node->left, new_data);
	else if (new_data > node->data)
		node->right = insert(node->right, new_data);
	else
		return node; // asumsi tidak boleh ada nilai yang sama dalam BST

	// 2. Update height dari node
	node->height = 1 + max(height(node->left), height(node->right));

	// 3. Hitung balance factor untuk menentukan apakah node unbalanced
	int balance = getBalanceFactor(node);

	// Jika tidak balanced, return hasil rotation
	// Kasus 1: Left Left
	if (balance > 1 && new_data < node->left->data)
		return rightRotate(node);

	// Kasus 2: Right Right
	if (balance < -1 && new_data > node->right->data)
		return leftRotate(node);

	// Kasus 3: Right Left
	if (balance < -1 && new_data < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	// Kasus 4: Left Right
	if (balance > 1 && new_data > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// return node jika balanced
	return node;
}

struct Node * minValueNode(struct Node* node) //cari node minimum di suatu subtree
{
    struct Node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}


struct Node* deleteNode(struct Node* root, int deleted_data)
{
    // 1. Lakukan BST delete biasa
    if (root == NULL)
        return root;

    if (deleted_data < root->data)
        root->left = deleteNode(root->left, deleted_data);

    else if(deleted_data > root->data)
        root->right = deleteNode(root->right, deleted_data);

    else
    { //jika ditemukan node yang akan dihapus
        // 1 CHILD atau NO CHILD
       struct Node* cursor;
        if (root->left == NULL)
        {
            cursor = root->right;
            free(root);
            root = cursor;
        }
        else if (root->right == NULL)
        {
            cursor = root->left;
            free(root);
            root = cursor;
        }
        //2 CHILDS
        else
        {
            // cari minimum di subtree kanan
            cursor = minValueNode(root->right);

            root->data = cursor->data;

            // Delete data yang telah dipindahkan sebagai root
            root->right = deleteNode(root->right, cursor->data);
        }
    }

    // Jika setelah dilakukan delete, tree kosong maka return root
    if (root == NULL)
      return root;

    // 2. Update height dari node
    root->height = 1 + max(height(root->left), height(root->right));

    // 3. Hitung balance factor untuk menentukan apakah root unbalanced
    int balance = getBalanceFactor(root);

    // Jika tidak balanced, return hasil rotation
	// Kasus 1: Left Left
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Kasus 2: Right Right
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Kasus 3: Right Left
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    // Kasus 4: Left Right
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // return root jika balanced
    return root;
}

void preOrder(struct Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
    struct Node *root = NULL;

//    root = insert(root, 10);
//    root = insert(root, 20);
//    root = insert(root, 30);
//    root = insert(root, 40);
//    root = insert(root, 50);
//    root = insert(root, 25);

    /* AVL Tree adalah sebagai berikut
            30
            / \
            20 40
            / \	 \
           10 25 50
    */

    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);

    /* AVL Tree
            9
           /  \
          1    10
        /  \     \
       0    5     11
      /    /  \
     -1   2    6
    */

    printf("Preorder traversal dari AVL tree adalah \n");
    preOrder(root);

    root = deleteNode(root, 10);

    /*AVL Tree setelah delete 10
            1
           /  \
          0    9
        /     /  \
       -1    5     11
           /  \
          2    6
    */

    printf("\nPreorder traversal dari AVL tree (setelah delete adalah \n");
    preOrder(root);

    return 0;
}
