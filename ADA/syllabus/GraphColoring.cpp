#include <iostream>
#include <vector>
using namespace std;

void nextValue(vector<vector<int>> graph, int n, int m, int k, int x[]) {
    // repeat unit a color is assigned to vertex k
    while(true) {
        // number between 0, m
        x[k] = (x[k] + 1) % (m + 1);
        // If all colors have been used
        if(x[k] == 0) return;
        // Check for adjacent vertices with same color
        int j; 
        for(j = 0; j < n; j++) {
            // If there is an edge and the nodes have same color
            if((graph[k][j] != 0) && (x[k] == x[j]))
                break;
        }
        // If no adjacent vertex has color x[k - 1] then return
        if(j == n) return;
    }
}

void mColoring(vector<vector<int>> graph, int n, int m, int k, int x[]) {
    // repeat until whole graph is colored
    while (true) {
        nextValue(graph, n, m, k, x);
        // If graph cant be colored then return
        if(x[k] == 0) return;  
        // If k == n qrite x
        if(k == n - 1) {
            for(int i = 0; i < n; i++)
                cout << x[i] << " ";
            cout << endl;
        }
        else mColoring(graph, n, m, k + 1, x);
    }
}

int main() {
    vector<vector<int>> graph = { {0, 1, 0, 1},
                                  {1, 0, 1, 0},
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0} };
    // Number of nodes in graph
    int n = 4;        
    // 2-Chromatic graph
    int m = 2;
    int x[n];
    for (int i = 0; i < n; i++)
        x[i] = 0;
    mColoring(graph, n, m, 0, x);
    
}