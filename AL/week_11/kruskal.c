//flag

#include <stdio.h>
#include <stdlib.h>
typedef struct edge {
	int src, des, weight;
}Edge;

int DFS(int **mat, int n, int visited[], int v) {
	visited[v] = 1;
	for(int i=0; i<n; i++) {
		if(mat[v][i] == 1) {
		 	if(visited[i] == 1)
				return 0;
			DFS(mat, n, visited, i);
		}
	}
	return 1;
}
int isCyclic(Edge edge, int **mat, int n) {
	mat[edge.src][edge.des] = 1;
	//mat[edge.des][edge.src] = 1;
	int visited[n];
	for(int i=0; i<n; i++) {
		visited[i] = 0;
	}

	int correct = DFS(mat, n, visited, edge.src);
	if(correct == 0) {
		mat[edge.src][edge.des] = 0;
		return 1;
	}
	return 0;
}

void sort(Edge edges[], int m) {
	for(int i=0; i<m-1; i++) {
		for(int j=0; j<m-i-1; j++) {
			if(edges[j].weight > edges[j+1].weight) {
				Edge temp = edges[j];
				edges[j] = edges[j+1];
				edges[j+1] = temp; 
			}
		}
	}
}
void kruskal(Edge edges[], int n, int m) {
	sort(edges, m);
	Edge added[n-1];
	int counter = 0;
	int **mat;
	mat = (int **)malloc(n*sizeof(int*));
	for(int i=0; i<n; i++) {
		mat[i] = (int *)malloc(n*sizeof(int));
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			mat[i][i] = 0;
	for(int i=0;i<n-1; i++) {
		if(!isCyclic(edges[i], mat, n)) {
			added[counter++] = edges[i];
		}
	}

}
int main() {
	int n;
	printf("Number of vertex\n");
	scanf("%d", &n);

	printf("Number of edges\n");
	int m;
	scanf("%d", &m);

	printf("%d\n", m);
	Edge *edges = (Edge*)malloc(m*sizeof(Edge));


	for(int i=0; i<m; i++) {
		scanf("%d ", &edges[i].weight);
		scanf("%d ", &edges[i].src);
		scanf("%d", &edges[i].des);
	}

	kruskal(edges, n, m);
	return 0;
}