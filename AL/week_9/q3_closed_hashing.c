//Algo Lab week 9, Q3

//By - Teja Juluru
//Created on - 10/10/19

//Implement closed hash table
#include<stdio.h>
#include<stdlib.h>
#define HASHTABLESIZE 10

int HashFunction(int ele) {
	return ele%HASHTABLESIZE;
}

int insert(int insert_ele,int* hash_table) {
	int key = HashFunction(insert_ele);
	if(hash_table[key] == -1) {
		hash_table[key] = insert_ele;
		return 1;
	}
	else {
		int temp = key;
		temp = (temp + 1)%HASHTABLESIZE;
		while(hash_table[temp] != -1 && temp != key) {
			temp = (temp + 1)%HASHTABLESIZE;
		}
		if(hash_table[temp] == -1 && temp != key) {
			hash_table[temp] = insert_ele;
			return 1;
		}
		else
			return 0;
	}
}

int search(int search_ele,int* hash_table,int* opcount) {
	int key = HashFunction(search_ele);
	(*opcount)++;
	if(hash_table[key] == search_ele) {
		return 1;
	}
	else {
		int temp = key;
		temp = (temp + 1)%HASHTABLESIZE;
		while(temp != key && hash_table[temp] != -1) {
			(*opcount)++;
			if(hash_table[temp] == search_ele) {
				return 1;
			}
			temp = (temp + 1)%HASHTABLESIZE;
		}
		return 0;
	}
}

int main(int argc, char const *argv[])
{
	int hash_table[HASHTABLESIZE];
	for(int i = 0;i < HASHTABLESIZE;i++)
		hash_table[i] = -1;

	int choice;
	while(1) {
		printf("1: insert, 2: search, 3: exit\n");
		printf("Enter choice : \n");
		scanf("%d",&choice);
		if(choice == 1) {
			int insert_ele;
			printf("Enter element to insert: ");
			scanf("%d",&insert_ele);
			if(insert(insert_ele,hash_table) == 0) {
				printf("Could not insert %d into the hash table\n",insert_ele);
			}
			
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
		// else if(choice == -1) { //debug
		// 	for(int i = 0;i < HASHTABLESIZE;i++)
		// 		printf("%d ",hash_table[i]);
		// 	printf("\n");
		// }
		else
			break;
	}
	return 0;
}