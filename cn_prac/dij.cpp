#include <iostream>
#include <climits>
using namespace std;

#define V 3

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1 || parent[j] == j) 
        return;

    printPath(parent, parent[j]);
    cout << (char)('A' + j) << "->";
}

void printSolution(int dist[], int parent[], int src) {
    cout << "Vertex\tDistance\tPath" << endl;
    for (int i = 0; i < V; i++) {
        if (i != src && dist[i] != INT_MAX) {
            cout << (char)('A' + src) << "->" << (char)('A' + i) << "\t" << dist[i] << "\t\t"<<"A->";
            printPath(parent, i);
            cout<<endl;
            // cout << (char)('A' + i) << endl;
        }
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, src);
}

int main() {
    int graph[V][V];
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cin>>graph[i][j];
        }
    }

    dijkstra(graph, 0);

    return 0;
}
