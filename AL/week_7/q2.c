//Algo Lab week 7, Experiment

//By - Teja Juluru
//Created on - 13/9/19

//Find the balance factor of every node in the BST
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int ele;
	int balance_factor;
	struct node* left;
	struct node* right;
}NODE;

NODE* CreateNode(int x) {
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->ele = x;
	new_node->left = new_node->right = NULL;
	new_node->balance_factor = 0;
	return new_node;
}

int max(int a,int b) {
	return(a >= b ? a : b);
}

int height(NODE* root) {
	if(root == NULL)
		return 0;
	else
		return(1 + max(height(root->left),height(root->right)));

}

void BalanceFactor(NODE* root) {
	if(root != NULL) {
		root->balance_factor = height(root->left) - height(root->right);
		// BalanceFactor(root->left);
		// BalanceFactor(root->right);
	}
}

NODE* RightRotate(NODE* root) {
	printf("Right rotate on node %d\n",root->ele);
	NODE* x = root->left;
	NODE* T2 = x->right;

	x->right = root;
	root->left = T2;

	return x;
}

NODE* LeftRotate(NODE* root) {
	printf("Left rotate on node %d\n",root->ele);
	NODE* y = root->right;
	NODE* T2 = y->left;

	y->left = root;
	root->right = T2;

	return y;
}

NODE* InsertBinarySearchTree(NODE* root,int x) {
	if(root == NULL) {
		// printf("root == NULL,x = %d\n",x);
		root = CreateNode(x);
		return root;
	}
	
	if(x < root->ele) {
		// printf("x < root->ele,x = %d,ele = %d,left\n",x,root->ele);
		root->left = InsertBinarySearchTree(root->left,x);
	}
	else if(x > root->ele) {
		// printf("x > root->ele,x = %d,ele = %d,right\n",x,root->ele);
		root->right = InsertBinarySearchTree(root->right,x);
	}
	else {
		// printf("duplicate,x = %d,root->ele = %d\n",x,root->ele);
		printf("ERROR. Duplicates not allowed\n");
		exit(0);
	}

	BalanceFactor(root);

	//Left left case
	if(root->balance_factor > 1 && x < root->left->ele) {
		return RightRotate(root);
	}

	//Right right case
	if(root->balance_factor < -1 && x > root->right->ele) {
		return LeftRotate(root);
	}

	//Left right case
	if(root->balance_factor > 1 && x > root->left->ele) {
		root->left = LeftRotate(root->left);
		return RightRotate(root);
	}

	//Right left case
	if(root->balance_factor < -1 && x < root->right->ele) {
		root->right = RightRotate(root->right);
		return LeftRotate(root);
	}

	return root;
}

//Update the balance factor of all the nodes
void final_balance(NODE* root) {
	if(root != NULL) {
		final_balance(root->left);
		BalanceFactor(root);
		final_balance(root->right);
	}
}

void inorder(NODE* root) {
	if(root != NULL) {
		inorder(root->left);
		printf("%d -> %d, ",root->ele,root->balance_factor);
		inorder(root->right);
	}
}

int main(int argc, char const *argv[])
{
	NODE* root = NULL;
	printf("Enter elements into the BST,(-1 to stop)\n");
	int ele = 0;
	while(1) {
		scanf("%d",&ele);
		if(ele == -1)
			break;
		root = InsertBinarySearchTree(root,ele);
	}
	// BalanceFactor(root);
	// printf("%d\n",root->ele);
	printf("The BST along with balance factor in inorder : \n");
	final_balance(root);
	inorder(root);
	printf("\n");
	return 0;
}