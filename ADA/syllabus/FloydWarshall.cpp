#include <iostream>
#include <vector>
#define INF 1000000
using namespace std;

void floydWarshall(vector<vector<int>> graph, int n) {
    int cost[n][n];

    // Intially cost matrix is same as the input graph
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cost[i][j] = graph[i][j];

    // Considering each vertext in the graph as intermediate vertex
    for(int k = 0; k < n; k++)
        // For each vertex in the graph 
        for(int i = 0; i < n; i++)
            // For each other vertex in the graph
            for(int j = 0; j < n; j++)
                // If cost of path from vertex i to j through k is less
                if(cost[i][k] + cost[k][j] < cost[i][j])
                    // Update cost of path from vertex i to vertex j
                    cost[i][j] = cost[i][k] + cost[k][j];

    // Output
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cost[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << cost[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    int n = 4;
    vector<vector<int>> graph = { {0,   8,  INF, 1},
                                  {INF,  0,  1,  INF},
                                  {4, INF, 0,   INF},
                                  {INF, 2, 9, 0} };

    floydWarshall(graph, n);

    return 0;
}