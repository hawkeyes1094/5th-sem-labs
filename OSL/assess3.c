//Assessment 3
//Implement LRU using a stack type simulation

//By - Teja Juluru
//Created on - 30/10/19

//Working code
//Just reverse the output of the print function.
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int ele;
	struct node* next;
}NODE;

typedef struct {
	int count;
	NODE* first;
}list;

NODE* createnode(int ele) {
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->ele = ele;
	temp->next = NULL;
	return temp;
}

void push(list* stk,int ele) {
	stk->count += 1;
	NODE* temp = createnode(ele);
	temp->next = stk->first;
	stk->first = temp;
	return;
}

void print(list stk) {
	NODE* temp = stk.first;
	while(temp != NULL) {
		printf("%d ",temp->ele);
		temp = temp->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int n;
	printf("no. of frames : \n");
	scanf("%d",&n);
	int pages[n];

	printf("references : (-1 to end)\n");
	int ref[100];
	int ref_count = 0;
	int x;
	while(1) {
		scanf("%d",&x);
		if(x < 0)
			break;
		ref[ref_count] = x;
		ref_count++;
	}

	list stk;
	stk.count = 0;
	stk.first = NULL;

	for(int i = 0;i < n;i++) {
		push(&stk,ref[i]);
	}

	NODE* temp = stk.first;
	while(temp != NULL) {
		printf("%d ",temp->ele);
		temp = temp->next;
	}
	printf("\n");

	int hit_count = 0;	
	for(int i = n;i < ref_count;i++) {
		temp = stk.first;
		int cur_ref = ref[i];
		int flag = 0;
		// printf("cur ref = %d\n",cur_ref);
		// printf("in while\n");
		while(temp->next != NULL) {
			// printf("%d = \n",temp->ele);
			if(temp->next->ele == cur_ref) { //found
				flag = 1;
				break;
			}
			temp = temp->next;
		}
		if(flag == 1) {
			NODE* temp2 = temp->next;
			temp->next = temp->next->next;
			temp2->next = stk.first;
			stk.first = temp2;
			printf("page hit for %d\n",cur_ref);
			hit_count++;
		}
		else {
			NODE* temp2 = stk.first;
			while(temp2->next->next != NULL) {
				temp2 = temp2->next;
			}
			temp2->next = NULL;
			push(&stk,cur_ref);
			printf("page miss for %d\n",cur_ref);
		}
		print(stk);
	}

	printf("\nhit count = %d\n",hit_count);
	return 0;
}