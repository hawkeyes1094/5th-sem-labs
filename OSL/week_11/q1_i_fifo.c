//Redo this

//OS Lab week 11, Q1, i

//By - Teja Juluru
//Created in - 16/10/19

//Simulate FIFO page replacement algorithm

//Such a dumbass. The pages are to be replaced in a linear order.
//No need for a queue. Change this shit.

#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int q_size;
	int cur_size;
	int head;
	int tail;
	int* arr[];
}queue;

queue* CreateQueue(int size) {
	queue* q = (queue*)malloc(sizeof(queue) + sizeof(int*)*size);
	q->q_size = size;
	q->cur_size = 0;
	q->head = q->tail = 0;
	return q;
}

int push(queue* q,int* x) {
	if(q->cur_size == q->q_size)
		return 0;
	q->arr[q->tail] = x;
	q->tail = (q->tail + 1)%(q->q_size);
	q->cur_size += 1;
	return 1;
}

int* pop(queue* q) {
	if(q->cur_size == 0)
		return NULL;
	int* temp = q->arr[q->head];
	q->head = (q->head + 1)%(q->q_size);
	q->cur_size -= 1;
	return temp;
}

int main(int argc, char const *argv[])
{
	printf("FIFO algorithm\n");
	int n;
	printf("Enter no. of pages : \n");
	scanf("%d",&n);
	int pages[n];

	//Initialize them to -1
	for(int i = 0;i < n;i++)
		pages[i] = -1;

	int page_request[100];
	printf("Enter the page requests (-1 to end) : \n");
	int i= 0,x = 0;
	while(1) {
		scanf("%d",&x);
		if(x < 0)
			break;
		page_request[i] = x;
		i++;
	}
	int no_of_requests = i;

	int head = 0;
	int hits = 0,faults = 0;

	//FIFO

	//FIFO queue
	queue* q = CreateQueue(n);
	for(int i = 0;i < n;i++)
		push(q,&pages[i]);

	int* hash_table[100];
	for(int i = 0;i < 100;i++)
		hash_table[i] = NULL;

	for(int i = 0;i < no_of_requests;i++) {
		if(hash_table[page_request[i]] == NULL) { //page not in memory
			faults++;
			int* location = pop(q); //Get the FIFO location
			int temp = *location;
			if(temp != -1) //If location not being used for the first time
				hash_table[temp] = NULL;

			*location = page_request[i];
			hash_table[page_request[i]] = location;
			push(q,location);
		}
		else { //page in memory
			hits++;
		}
	}
	printf("page faults = %d, hits = %d\n",faults,hits);
	return 0;
}