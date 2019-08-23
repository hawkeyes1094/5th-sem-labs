//Algo Lab week 5, Q2

//By - Teja Juluru
//Created on - 23/8/19

//Program to find diameter of binary tree
#include<stdio.h>
#include<stdlib.h>

typdef sruct node{
	int ele;
	struct node* left;
	sruct node* right;
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

int height(NODE* root) {
	
}

int main(int argc, char const *argv[])
{
	NODE* root = CreateBinaryTree();
	return 0;
}