//Algo lab week 1, Q2

//by - Teja Juluru
//created on 23/07/19

//adjacency list and matrix
#include<stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int choice = 0;
	printf("For undirected graph, enter 1\n");
	printf("For directed graph, enter 2\n");
	do{
		printf("Enter choice : ");
		scanf("%d",&choice);
	}while(coice != 1 || choice != 2); //keep looping until correct choice
	
	int no_of_nodes = 0;;
	printf("Enter the number of nodes : ");
	scanf("%d",&no_of_nodes);

	//create a sq matrix of size no_of_nodes
	int** matrix = (int**) malloc(no_of_nodes*sizeof(int*));
	for (int i = 0; i < no_of_nodes; i++) {
		matrix[i] = (int*)malloc(sizeof(int));
	}
	//

	int no_of_edges = 0;
	printf("Enter number of edges : ");
	scanf("%d",&no_of_edges);

	switch (choice) {
		case 1 : {
			int start_node = 0,end_node = 0;
			for (int i = 0; i < no_of_edges; ++i) {
				
			}
		}
	}
	return 0;
}