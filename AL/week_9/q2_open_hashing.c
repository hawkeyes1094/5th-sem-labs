//Algo Lab week 9, Q2

//By - Teja Juluru
//Created on - 10/10/19

//Implement open hash table
#include<stdio.h>
#include<stdlib.h>
#define HASHTABLESIZE 10

struct node{
	int data;
	struct node* next;
};

struct node* CreateNode(int x) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = x;
	new_node->next = NULL;
	return new_node;
}

int HashFunction(int ele) {
	return ele%HASHTABLESIZE;
}

void insert(int insert_ele,struct node** hash_table) {
	int key = HashFunction(insert_ele);
	if(hash_table[key] == NULL) {
		hash_table[key] = CreateNode(insert_ele);
	}
	else {
		struct node* cur_node = hash_table[key];
		while(cur_node->next != NULL)
			cur_node = cur_node->next;
		cur_node->next = CreateNode(insert_ele);
	}
}

int search(int search_ele,struct node** hash_table,int* opcount) {
	int key = HashFunction(search_ele);
	(*opcount)++; //count the if condition
	if((hash_table[key])->data == search_ele) {
		return 1;
	}
	else { 
		struct node* cur_node = hash_table[key]->next;
		while(cur_node->data != search_ele && cur_node != NULL) {
			(*opcount)++;
			cur_node = cur_node->next;
		}
		(*opcount)++;
		if(cur_node == NULL)
			return 0;
		else
			return 1;
	}
}

int main(int argc, char const *argv[])
{
	struct node* hash_table[HASHTABLESIZE];
	for(int i = 0;i < HASHTABLESIZE;i++)
		hash_table[i] = NULL;

	int choice;
	while(1) {
		printf("1: insert, 2: search, 3: exit\n");
		printf("Enter choice : \n");
		scanf("%d",&choice);
		if(choice == 1) {
			int insert_ele;
			printf("Enter element to insert: ");
			scanf("%d",&insert_ele);
			insert(insert_ele,hash_table);
		}
		else if(choice == 2) {
			int opcount = 0;
			int search_ele;
			printf("Enter element to search : ");
			scanf("%d",&search_ele);
			if(search(search_ele,hash_table,&opcount)) 
				printf("Found in hash table\n");
			else
				printf("Not found\n");
			printf("opcount = %d\n",opcount);
		}
		else
			break;
	}

	// printf("Hash table : \n");
	// for(int i = 0;i < HASHTABLESIZE;i++) {
	// 	struct node* cur_node = hash_table[i];
	// 	while(cur_node != NULL) {
	// 		printf("%d->",cur_node->data);
	// 		cur_node = cur_node->next;
	// 	}
	// 	printf("\n");
	// }
	return 0;
}