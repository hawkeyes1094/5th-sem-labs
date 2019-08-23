//Algo Lab week 5, Q2

//By - Teja Juluru
//Created on - 23/8/19

//Program to find diameter of binary tree
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
	new_node->right = NULL;
	new_node->left = NULL;
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

int max(int a,int b) {
	return(a >= b ? a : b);
}

int height(NODE* root) {
	if(root == NULL)
		return 0;
	return(1 + max(height(root->left),height(root->right)));
}

int diameter(NODE* root) {
	if(root == NULL)
		return 0;

	//get the height of left and right subtree
	int left_height = height(root->left);
	int right_height = height(root->right);

	//get the diameter of left and right subtree
	int left_diameter = diameter(root->left);
	int right_diameter = diameter(root->right);

	//return the max of
	//1. left_height + right_height + 1
	//2. left_diameter
	//3. right_diameter
	return( max( left_height+right_height+1, max(left_diameter,right_diameter) ) );
}

int main(int argc, char const *argv[])
{
	NODE* root = CreateBinaryTree();

	int tree_diameter = diameter(root);
	printf("diameter = %d\n",tree_diameter);
	return 0;
}