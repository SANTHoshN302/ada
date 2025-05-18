/* From a given vertex in a weighted connected graph, find
shortest paths to other vertices using Dijkstra’s
algorithm. */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 100

int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(int graph[MAX][MAX], int V, int src) {
    int dist[V];     
    int visited[V];   

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0; 

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("\nVertex\tDistance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d\t\t%d\n", i, dist[i]);
}

int main() {
    int V, E;
    int graph[MAX][MAX] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter edges in the format: source destination weight\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, V, src);

    return 0;
}

/* OUTPUT
Enter the number of vertices: 5
Enter the number of edges: 7
Enter edges in the format: source destination weight
0 1 10
0 4 5
1 2 1
1 4 2
2 3 4
3 0 7
4 2 9
Enter the source vertex: 0

Vertex  Distance from Source 0
0       0
1       8
2       9
3       13
4       5

*/
*/
