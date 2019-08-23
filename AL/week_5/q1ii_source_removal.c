//Algo Lab week 5, Q1ii

//By - Teja Juluru
//Created on - 23/8/19

//Determine the topological sort of a graph
// using source removal technique.
//note - this algo orks only for *directed* acyclic graphs
#include<stdio.h>
#include<stdlib.h>
#define Q_MAX_SIZE 256

typedef struct{
	int size;
	int left;
	int right;
	int arr[Q_MAX_SIZE];
}QUEUE;

QUEUE* CreateQueue() {
	QUEUE* q = (QUEUE*)malloc(sizeof(QUEUE));
	q->left = 0;
	q->right = 0;
	q->size = 0;
	return q;
}

void Enqueue(QUEUE* q,int n) {
	if(q->right == Q_MAX_SIZE) {
		printf("buffer full\n");
		return;
	}
	q->arr[q->right] = n;
	q->right += 1;
	q->size += 1;
}

int Dequeue(QUEUE* q) {
	if(q->size == 0) {
		printf("queue empty\n");
		return -1;
	}
	int temp = q->arr[q->left];
	q->left += 1;
	q->size -= 1;
	return temp;
}



int main(int argc, char const *argv[])
{
	int no_of_vertices;
	printf("Enter the number of vertices : ");
	scanf("%d",&no_of_vertices);

	//create the adjacency matrix
	int** adjacency_matrix = (int **)malloc(no_of_vertices*sizeof(int*));
	for(int i = 0;i < no_of_vertices;i++)
		adjacency_matrix[i] = (int*)malloc(no_of_vertices*sizeof(int));

	int no_of_edges;
	printf("Enter the number of edges : ");
	scanf("%d",&no_of_edges);

	//enter the edges info into the adjacency matrix
	//graph is directed
	int edge1,edge2;
	printf("This is a directed graph\n");
	for(int i = 0;i < no_of_edges;i++) {
		scanf("%d",&edge1);
		scanf("%d",&edge2);
		adjacency_matrix[edge1-1][edge2-1] = 1;
	}

	//create the in_degree array
	int* in_degree = (int*)malloc(no_of_vertices*sizeof(int));

	//find the in-degree of the vertices
	for(int i = 0;i < no_of_vertices;i++) {
		for(int j = 0;j < no_of_vertices;j++) {
			if(adjacency_matrix[i][j] == 1) {
				in_degree[j] += 1;
			}
		}
	}

	//print in_degree
	// for(int i = 0;i < no_of_vertices;i++)
	// 	printf("%d ",in_degree[i]);
	// printf("\n");

	//enqueue all vertices with 0 in-degree
	QUEUE* q = CreateQueue();
	for(int i = 0;i < no_of_vertices;i++) {
		if(in_degree[i] == 0)
			Enqueue(q,i);
	}

	int visited_count = 0;
	printf("topological sort : \n");
	while(q->size > 0) { //repeat until queue is empty
		int node = Dequeue(q);
		printf("%d ",node+1);
		visited_count++;
		for(int i = 0;i < no_of_vertices;i++) {
			if(adjacency_matrix[node][i] == 1) {
				in_degree[i] -= 1; //decrement in-degree of neighbours
				if(in_degree[i] == 0)
					Enqueue(q,i);//if in-degree of neighbour is 0, enqueue it
			}
		}
	}
	printf("\n");

	return 0;
}