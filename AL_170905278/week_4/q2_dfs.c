//Algo Lab week 4, Q2

//By - Teja Juluru

//Program for depth first search of a graph
//Also print the push and pop order of the vertices
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int ele[256];
	int top;
}stack;

void stack_init(stack* stk) {
	stk->top = -1;
}

void push(stack* stk,int n) {
	stk->top += 1;
	stk->ele[stk->top] = n;
}

int pop(stack* stk) {
	if(stk->top != -1) {
		int temp = stk->ele[stk->top];
		stk->top -= 1;
		return temp;
	}
}

//DFS traversal
void dfsv(int** graph,int n,int* visited,int i,stack* stk) {
	printf("visiting node %d\n",i+1);
	// push(stk,i+1);
	visited[i] = 1;
	for(int j = 0;j < n;j++) {
		if(!visited[j] && graph[i][j])
			dfsv(graph,n,visited,j);
	}
}

void dfs(int** graph,int no_of_vertices,int* visited) {
	for(int i = 0;i < no_of_vertices;i++) {
		if(!visited[i])
			dfsv(graph,no_of_vertices,visited,i);
	}
}
//

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
	int edge1,edge2;
	for(int i = 0;i < no_of_edges;i++) {
		scanf("%d",&edge1);
		scanf("%d",&edge2);
		adjacency_matrix[edge1-1][edge2-1] = adjacency_matrix[edge2-1][edge1-1] = 1;
	}

	int* visited = (int*)malloc(no_of_vertices*sizeof(int));

	dfs(adjacency_matrix,no_of_vertices,visited);

	
	return 0;
}