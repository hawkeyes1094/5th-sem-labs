//Algo Lab week 4, Q3

//By - Teja Juluru
//Created on - 22/8/19

//Program for BFS traversal of a graph
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int ele;
	struct node* next;
}NODE;

typedef struct{
	NODE* front;
	NODE* rear;
	int size;
}Q;

NODE* CreateNode(int n) {
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->ele = n;
	new_node->next = NULL;
	return new_node;
}

Q* CreateQueue() {
	Q* queue = (Q*)malloc(sizeof(Q));
	queue->front = NULL;
	queue->rear = NULL;
	queue->size = 0;
	return queue;
}

void Enqueue(Q* queue,int n) {
	if(queue == NULL) {
		queue = CreateQueue();
	}
	NODE* new_node = CreateNode(n);
	if(queue->size == 0) { //if empty queue
		queue->front = queue->rear = new_node;
		queue->size += 1;
	}
	else {
		queue->rear->next = new_node;
		queue->rear = new_node;
		queue->size += 1;
	}
}

int Dequeue(Q* queue) {
	int val = queue->front->ele;
	queue->size -= 1;
	if(queue->size == 0) { //if empty queue
		queue->front = queue->rear = NULL;
	}
	else {
		NODE* temp = queue->front;
		queue->front = queue->front->next;
		free(temp);
	}
	return val;
}

void bfs(int** adjacency_matrix,int no_of_vertices,int* visited) {
	Q* queue = CreateQueue();
	Enqueue(queue,0);
	// printf("enqueued 1\n");

	while(queue->size > 0) {
		int node = Dequeue(queue);
		// printf("dequeued %d\n",node+1);
		printf("visited node %d\n",node+1);
		visited[node] = 1;
		for(int i = 0;i < no_of_vertices;i++) {
			if(adjacency_matrix[node][i] == 1 && visited[i] != 1) {
				Enqueue(queue,i);
				visited[i] = 1;  //mark visited even if enqueued. Prevents duplicates
				// printf("enqueued %d\n",i+1);
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	int no_of_vertices;
	printf("Enter no of vertices : ");
	scanf("%d",&no_of_vertices);

	//create the adjacency matrix
	int** adjacency_matrix = (int **)malloc(no_of_vertices*sizeof(int*));
	for(int i = 0;i < no_of_vertices;i++)
		adjacency_matrix[i] = (int*)malloc(no_of_vertices*sizeof(int));

	int no_of_edges;
	printf("Enter the number of edges : ");
	scanf("%d",&no_of_edges);

	//enter the edges info into the adjacency matrix
	int edge1,edge2;
	for(int i = 0;i < no_of_edges;i++) {
		scanf("%d",&edge1);
		scanf("%d",&edge2);
		adjacency_matrix[edge1-1][edge2-1] = adjacency_matrix[edge2-1][edge1-1] = 1;
	}

	//create the visited array to mark a node once it is visited
	int* visited = (int*)malloc(no_of_vertices*sizeof(int));

	bfs(adjacency_matrix,no_of_vertices,visited);
	return 0;
}