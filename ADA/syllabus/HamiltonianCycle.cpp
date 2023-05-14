#include <iostream>
#include <vector>
using namespace std;

void nextValue(vector<vector<int>> graph, int n, int k, int x[]) {
    while(true) {
        x[k] = (x[k] + 1) % (n + 1);
        if(x[k] == 0) return;

        if((graph[k - 1][k] != 0)) {
            int j;
            for(j = 0; j < n; j++) {
                
        }
        if(j == n) return;
    }
}

void hamiltonian(vector<vector<int>> graph, int n, int k, int x[]) {
    // repeat until whole graph is traversed
    while (true) {
        nextValue(graph, n, k, x);
        if(x[k] == 0) return;  
        // If k == n qrite x
        if(k == n - 1) {
            for(int i = 0; i < n; i++)
                cout << x[i] << " ";
            cout << endl;
        }
        else hamiltonian(graph, n, k + 1, x);
    }
}

int main() {
    vector<vector<int>> graph = { {0, 1, 0, 1},
                                  {1, 0, 1, 0},
                                  {0, 1, 0, 1},
                                  {1, 0, 1, 0} };
    // Number of nodes in graph
    int n = 4;        
    
    int x[n];
    for (int i = 0; i < n; i++)
        x[i] = 0;
    hamiltonian(graph, n, 0, x);
    
}