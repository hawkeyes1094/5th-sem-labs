//Algo Lab week 11, Q1

//By - Teja Juluru
//Created on - 11/10/19

//Kruskal's algorithm
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int node1;
	int node2;
	int weight;
}edge;

void sort(edge* edges,int no_of_edges) {
	for(int i = 0;i < no_of_edges;i++) {
		for(int j = 0;j < no_of_edges-i-1;j++) {
			if(edges[j].weight > edges[j+1].weight) {
				edge temp = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = temp;
			}
		}
	}
}

int IsCycle(int** min_spanning_tree,int n,int* visited,int current) {
	if(visited[current] != 1) {
		visited[current] = 1;
		for(int j = 0;j < n;j++) {
			if(min_spanning_tree[current][j] != 0 && visited[j] == 0) {
				return IsCycle(min_spanning_tree,n,visited,current);
			}
			if(visited[j] == 1)
				return 1;
		}
		return 0;
	}
}

int main(int argc, char const *argv[])
{
	printf("Enter no. of nodes : \n");
	int n;
	scanf("%d",&n);

	printf("Enter no. of edges : \n");
	int no_of_edges;
	scanf("%d",&no_of_edges);

	edge* edges = (edge*)malloc(no_of_edges*sizeof(edge));

	printf("Enter node1, node2, weight of the edges : \n");
	for(int i = 0;i < no_of_edges;i++) {
		scanf("%d",&(edges[i].node1));
		scanf("%d",&(edges[i].node2));
		scanf("%d",&(edges[i].weight));
	}

	sort(edges,no_of_edges);
	printf("After sorting : \n");
	for(int i = 0;i < no_of_edges;i++) {
		printf("%d %d %d\n",edges[i].node1,edges[i].node2,edges[i].weight);
	}

	int** min_spanning_tree = (int**)malloc(n*sizeof(int*));
	for(int i = 0;i < n;i++)
		min_spanning_tree[i] = (int*)malloc(n*sizeof(int));

	int edge_no = 0;
	int edge_count = 0;
	int* visited = malloc(n*sizeof(int));
	while(edge_count <= n - 1) {
		min_spanning_tree[edges[edge_no].node1 - 1][edges[edge_no].node2 - 1] = edges[edge_no].weight;
		min_spanning_tree[edges[edge_no].node2 - 1][edges[edge_no].node1 - 1] = edges[edge_no].weight;
		if(IsCycle(min_spanning_tree,n,visited,edges[edge_no].node1)) {
			min_spanning_tree[edges[edge_no].node1 - 1][edges[edge_no].node2 - 1] = 0;
			min_spanning_tree[edges[edge_no].node2 - 1][edges[edge_no].node1 - 1] = 0;
		}
		else {
			edge_count++;
		}
		edge_no++;
	}

	printf("End of while loop\n");
	
	int min_weight = 0;
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			min_weight += min_spanning_tree[i][j];
		}
	}
	// min_weight = min_weight/2;

	printf("min weight = %d\n",min_weight);
	return 0;
}