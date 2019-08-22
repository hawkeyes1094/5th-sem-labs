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
		printf("duplicates not allowed.\n");
		exit(0);
	}
}
//

//search for element in BST
int search(node* root,int search_ele) {
	if(root == NULL) {
		return 0;
	}
	if(root->element == search_ele) {
		return 1;
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

	//Search for a key in the BST. If not found, insert into it
	printf("Enter a key to search for it. If not found, will be inserted into the BST\n");
	int key = 0;
	scanf("%d",&key);
	if(search(root,key))
		printf("element found\n");
	else {
		printf("Not in the BST, inserting\n");
		insert(root,key);
	}
	//

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
