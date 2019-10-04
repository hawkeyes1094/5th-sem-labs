//Algo Lab week 10, Q1

//By - Teja Juluru
//Created on - 4/10/19

//Warshall's algorithm to find the 
// transitive closure of a digraph
#include<stdio.h>
#include<stdlib.h>

int** Warshall(int** adjacency_matrix,int n) {
	int** R = (int**)malloc(n*sizeof(int*));
	for(int i = 0;i < n;i++) {
		R[i] = (int*)malloc(n*sizeof(int));
		for(int j = 0;j < n;j++) {
			R[i][j] = adjacency_matrix[i][j];
		}
	}

	for(int k = 0;k < n;k++) {
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++)
				R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
		}
	}

	return R;
}

int main(int argc, char const *argv[])
{
	int no_of_vertices;
	printf("Directed graph\n");
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

	int** R = Warshall(adjacency_matrix,no_of_vertices);

	//print the transitive closure digraph
	printf("\nTransitive closure of the digraph is : \n");
	for(int i = 0;i < no_of_vertices;i++) {
		for(int j = 0;j < no_of_vertices;j++) {
			printf("%d ",R[i][j]);
		}
		printf("\n");
	}
	return 0;
}