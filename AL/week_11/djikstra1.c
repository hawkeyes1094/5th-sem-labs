//flag

#include <limits.h> 
#include <stdio.h>
int n;

int mDis(int dist[], int included[]) { 
    int min = INT_MAX, min_index; 
    for (int v = 0; v < n; v++) 
        if (included[v] == 0 && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
int solution(int dist[]) { 
    for (int i = 0; i < n; i++) 
        printf("%d \t -> \t %d\n", i, dist[i]); 
} 

void dijkstra(int mat[n][n], int src) { 
    int dist[n];
  
    int included[n];
    for (int i = 0; i < n; i++) 
        dist[i] = INT_MAX;

    for(int i=0; i<n; i++)
        included[i] = 0;

    dist[src] = 0;

    for (int i = 0; i < n-1; i++) { 
        int u = mDis(dist, included); 
        included[u] = 1; 
        for (int v = 0; v < n; v++) 
            if (!included[v] && mat[u][v] && dist[u] != INT_MAX && dist[u] + mat[u][v] < dist[v]) 
                dist[v] = dist[u] + mat[u][v]; 
    } 
    solution(dist); 
} 
  
int main() {
    printf("Number of vertex\n");
    scanf("%d", &n);
    printf("Enter Matrix\n");
    int mat[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            scanf("%d", &mat[i][j]);
    }
    dijkstra(mat, 0); 
  
    return 0; 
}