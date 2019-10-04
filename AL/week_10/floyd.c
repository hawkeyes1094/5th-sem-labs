//Algo Lab week 10, Q2

//By - Teja Juluru
//Created on - 4/10/19

//Floyd's algorithm for all-pairs
// shortest-paths problem.
#include<stdio.h>
#include<stdlib.h>

int min(int a,int b) {
	if(a <= b)
		return a;
	else
		return b;
}

int** Floyd(int** weight_matrix,int n) {
	int** D = (int**)malloc(n*sizeof(int*));
	for(int i = 0;i < n;i++) {
		D[i] = (int*)malloc(n*sizeof(int));
		for(int j = 0;j < n;j++) {
			D[i][j] = weight_matrix[i][j];
		}
	}

	for(int k = 0;k < n;k++) {
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < n;j++) {
				D[i][j] = min(D[i][j],D[i][k] + D[k][j]);
			}
		}
	}

	return D;
}

int main(int argc, char const *argv[])
{
	int no_of_vertices;
	printf("Enter the number of vertices : ");
	scanf("%d",&no_of_vertices);

	//declare the weight matrix
	int** weight_matrix = (int**)malloc(no_of_vertices*sizeof(int*));
	for(int i = 0;i < no_of_vertices;i++) {
		weight_matrix[i] = (int*)malloc(no_of_vertices*sizeof(int));
		for(int j = 0;j < no_of_vertices;j++) {
			weight_matrix[i][j] = 99999;
			if(i == j)
				weight_matrix[i][j] = 0;
		}
	}

	int no_of_edges;
	int v1,v2,dist;
	printf("Directed graph\n");
	printf("Enter the number of edges : ");
	scanf("%d",&no_of_edges);
	printf("Enter the initial and final vertex of the edge, and the distance\n");
	for(int i = 0;i < no_of_edges;i++) {
		scanf("%d",&v1);
		scanf("%d",&v2);
		scanf("%d",&dist);
		weight_matrix[v1-1][v2-1] = dist;
	}

	int** D = Floyd(weight_matrix,no_of_vertices);

	printf("The shortest paths are : \n");
	for(int i = 0;i < no_of_vertices;i++) {
		for(int j = 0;j < no_of_vertices;j++) {
			printf("%d ",D[i][j]);
		}
		printf("\n");
	}
	return 0;
}