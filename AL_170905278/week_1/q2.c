//Algo lab week 1, Q2

//by - Teja Juluru
//created on 23/07/19

//adjacency list and matrix
#include<stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int node_number;
	int no_of_edges;
	int edges[];
}node;
//for an undirected graph, the entry of the other node is
// in both the nodes which have an edge between them

//for a directed graph, the entry of the destination node
// is in the source node


int main(int argc, char const *argv[])
{
	int choice = 0;
	printf("For undirected graph, enter 1\n");
	printf("For directed graph, enter 2\n");
	do{
		printf("Enter choice : ");
		scanf("%d",&choice);

	}while(choice != 1 && choice != 2); //keep looping until correct choice
	int no_of_nodes = 0;
	printf("Enter the number of nodes : ");
	scanf("%d",&no_of_nodes);

	int no_of_edges = 0;
	printf("Enter number of edges : ");
	scanf("%d",&no_of_edges);

	//create a sq matrix of size no_of_nodes for adjacency matrix
	//all entries are 0 by default
	int** matrix = (int**) malloc(no_of_nodes*sizeof(int*));
	for (int i = 0; i < no_of_nodes; i++) {
		matrix[i] = (int*)malloc(no_of_nodes*sizeof(int));
	}

	//create a 2*no_of_edges matrix for edges info
	int** edges_matrix = (int**)malloc(2*sizeof(int*));
	edges_matrix[0] = (int*)malloc(no_of_edges*sizeof(int));
	edges_matrix[1] = (int*)malloc(no_of_edges*sizeof(int));

	//input edges info
	printf("Enter edges info : \n");
	for (int i = 0; i < no_of_edges; ++i) {
		scanf("%d %d",&edges_matrix[0][i],&edges_matrix[1][i]);
	}

	//enter edges info into adjacency matrix
	for(int i = 0;i < no_of_edges;i++) {
		if(choice == 1) {  //undirected graph

			//the source & dest node info is saved in edges_matrix
			//there are two entries for an edge in the adacency matrix
			matrix[edges_matrix[0][i]-1][edges_matrix[1][i]-1] = 1;
			matrix[edges_matrix[1][i]-1][edges_matrix[0][i]-1] = 1;

		}
		else{  //directed graph

			//there is only one entry for an edge in the adgacency matrix
			matrix[edges_matrix[0][i]-1][edges_matrix[1][i]-1] = 1;

		}
	}

	//print the adjacency matrix
	printf("adjacency matrix : \n");
	for(int i = 0;i < no_of_nodes;i++) {
		for (int j = 0;j < no_of_nodes;j++) {
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}

	//create the nodes using adjaceny matrix
	node** graph = (node**)malloc(no_of_nodes*sizeof(node*));

	for(int i = 0;i < no_of_nodes;i++) {
		int temp = 0; //tmep var to store to number of entries
		for(int j = 0;j < no_of_nodes;j++)
			temp += matrix[i][j];

		//create a node
		graph[i] = (node *)malloc(sizeof(node) + temp*sizeof(int));
		graph[i]->no_of_edges = 0;

		//enter edge info into node
		for(int j = 0;j < no_of_nodes;j++) {
			if(matrix[i][j] == 1) {
				//Store the node number in the edges array
				graph[i]->edges[graph[i]->no_of_edges] = j+1;
				graph[i]->no_of_edges += 1;
			}
		}
	}


	//print the adjacency list
	for(int i = 0;i < no_of_nodes;i++) {
		printf("%d",i+1);
		for(int j = 0;j < graph[i]->no_of_edges;j++) {
			printf("->%d",graph[i]->edges[j]);
		}
		printf("\n");
	}

	return 0;
}
