//Algo Lab week 5, Q1i

//By - Teja Juluru
//Created on - 23/8/19

//Determine topological sort of a graph
// using DFS
#include<stdio.h>
#include<stdlib.h>

//DFS traversal
void dfs(int** adjacency_matrix, int no_of_vertices,int* visited,int current,int* pop_order,int* pop_order_count) {
	if(visited[current] != 1) {
		//mark the node as visited
		visited[current] = 1;
		// printf("pushed node %d\n",current+1);
		for(int j = 0;j < no_of_vertices;j++) {
			if(adjacency_matrix[current][j]  == 1 && visited[j] == 0) {
				dfs(adjacency_matrix,no_of_vertices,visited,j,pop_order,pop_order_count);
				// printf("popped node %d\n",j+1);
				pop_order[*pop_order_count] = j+1;
				*pop_order_count += 1;
			}
		}
	}
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
	int edge1,edge2;
	for(int i = 0;i < no_of_edges;i++) {
		scanf("%d",&edge1);
		scanf("%d",&edge2);
		adjacency_matrix[edge1-1][edge2-1] = adjacency_matrix[edge2-1][edge1-1] = 1;
	}

	//create the visited array to mark a node once it is visited
	int* visited = (int*)malloc(no_of_vertices*sizeof(int));

	int*pop_order = (int*)malloc(no_of_vertices*sizeof(int));
	int pop_order_count = 0;
	dfs(adjacency_matrix,no_of_vertices,visited,0,pop_order,&pop_order_count);
	// printf("popped node 1\n");
	pop_order[pop_order_count] = 1;
	pop_order_count++;

	printf("reverse of pop order : \n");
	for(int i = pop_order_count-1;i >= 0;i--)
		printf("%d ",pop_order[i]);
	printf("\n");
	return 0;
}