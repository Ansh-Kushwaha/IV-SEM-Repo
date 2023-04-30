#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000

int getMinimumDist(int v, int dist[], int n, bool s[]) {
    int minDist = INF;
    int node = 0;
    for(int i = 0; i < n; i++) {
        if(!s[i] && dist[i] <= minDist) {
            minDist = dist[i];
            node = i;
        }
    }
    return node;
}

void dijkstra(vector<vector<int>> graph, int v, int dist[], int n) {
    bool s[n];

    for(int i = 0; i < n; i++)
        s[i] = false;
    
    dist[v] = 0;
    for(int i = 1; i < n; i++) {
        dist[i] = INF;
    }

    for(int i = 0; i < n - 1; i++) {
        int u = getMinimumDist(i, dist, n, s);
        s[u] = true;
        for(int w = 0; w < graph[u].size(); w++)
            if(!s[w] && graph[u][w] != INF)
                if(dist[w] > dist[u] + graph[u][w])
                    dist[w] = dist[u] + graph[u][w];
    }
}

int main() {
    int v = 6;
    int s = 0;
    vector<vector<int> > graph = { {0, 4, 5, INF, INF, INF},      // cost
                                   {4, 0, 11, 9, 7, INF},
                                   {5, 11, 0, INF, 3, INF},
                                   {INF, 9, INF, 0, 13, 2},
                                   {INF, 7, 3, 13, 0, 6},
                                   {INF, INF, INF, 2, 6, 0} };
    int dist[6];
    dijkstra(graph, s, dist, v);
    cout << "\tNode\tDist\n";
    for(int i = 0; i < v; i++) {
        cout << "\t" << (char) (65 + i) << "\t" << dist[i] << "\n";
    }
    return 0;
}