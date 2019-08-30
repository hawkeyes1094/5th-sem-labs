//Algo Lab week 6, Q1

//By - Teja Juluru
//Created on - 30/8/19

//Find the number of nodes in a binary tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int ele;
	struct node* left;
	struct node* right;
}NODE;

NODE* NewNode(int x) {
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->ele = x;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

NODE* CreateBinaryTree() {
	NODE* root;
	int x;
	printf("Enter data(-1 for nothing) : \n");
	scanf("%d",&x);

	if(x == -1)
		return NULL;

	root = NewNode(x);

	printf("Enter left child of %d\n",root->ele);
	root->left = CreateBinaryTree();

	printf("Enter right child of %d\n",root->ele);
	root->right = CreateBinaryTree();

	return root;
}

int NodeCount(NODE* root,int* opcount) {
	(*opcount)++;
	if(root == NULL)
		return 0;
	return(NodeCount(root->left,opcount) + NodeCount(root->right,opcount) + 1);
}

int main(int argc, char const *argv[])
{
	NODE* root = CreateBinaryTree();
	int opcount = 0;
	int node_count = NodeCount(root,&opcount);
	printf("\nNumber of nodes in the tree = %d\n",node_count);
	printf("opcount = %d\n",opcount);
	return 0;
}