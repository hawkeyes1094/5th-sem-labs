//Algo lab week 1, Q1

//by - Teja Juluru
//created on 23/07/19

//BST 
#include<stdio.h>
#include<stdlib.h>

typedef struct NODE{
	struct NODE* left;
	int element;
	struct NODE* right;
}node;

//function to create a new node
node* create_node(int element) {
	node* newnode = (node*)malloc(sizeof(node));
	newnode->element = element;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
//

//function to insert element into BST
node* insert(node* root,int element) {
	if(root == NULL) { //create root node
		root = create_node(element);
		return root;
	}
	if(element < root->element) {
		root->left = insert(root->left,element);
	}
	else if(element > root->element) {
		root->right = insert(root->right,element);
	}
	else {
		printf("duplicate\n");
		exit(0);
	}
}
//

//search for element in BST
void search(node* root,int search_ele) {
	if(root == NULL) {
		printf("element not found\n");
		return;
	}
	if(root->element == search_ele) {
		printf("element found\n");
		return;
	}
	else if(search_ele < root->element) {
		search(root->left,search_ele);
	}
	else {
		search(root->right,search_ele);
	}
}
//

//inorder traversal
void inorder(node* root) {
	if(root != NULL) {
		inorder(root->left);
		printf("%d ",root->element);
		inorder(root->right);
	}
}
//

//preorder traversal
void preorder(node* root) {
	if(root != NULL) {
		printf("%d ",root->element);
		preorder(root->left);
		preorder(root->right);
	}
}
//

//postorder traversal
void postorder(node* root) {
	if(root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->element);
	}
}
//

int main(int argc, char const *argv[])
{
	printf("Program to create BST\n");
	node* root = NULL;
	int temp = 0;
	while(1) {
		printf("Enter a number to insert into BST, -1 to end : ");
		scanf("%d",&temp);
		if(temp == -1)
			break;
		root = insert(root,temp);
	}
	printf("inorder traversal : \n");
	inorder(root);
	printf("\n");
	printf("preorder traversal : \n");
	preorder(root);
	printf("\n");
	printf("postorder traversal : \n");;
	postorder(root);
	printf("\n");
	return 0;
}