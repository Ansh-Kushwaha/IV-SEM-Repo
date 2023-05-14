#include <iostream>
#include <vector>
using namespace std;

int num = 1;

void nextValue(vector<vector<int>> graph, int n, int k, int x[]) {
    // Repeat until false
    while(true) {
        // Assign highest number vertex not already in x
        x[k] = (x[k] + 1) % n;
        // cout << "assigned " << x[k] << endl;

        if(x[k] == 0) return;
        // If there is an edge between previous vertex and current vertex in the path
        if((graph[x[k - 1]][x[k]] != 0)) {

            int j;
            // For each previously visited vertex
            for(j = 0; j < k - 1; j++) {
                if(x[j] == x[k]) break;
            }

            if(j == k - 1)
                if((k < n - 1) || (k == n - 1 && graph[x[n - 1]][x[0]] != 0)) return;
        }
    }
}

void hamiltonian(vector<vector<int>> graph, int n, int k, int x[]) {
    // Repeat until false
    while (true) {
        // Assign a legal values for x[k]
        nextValue(graph, n, k, x);
        // If no value can be assigned then return
        // cout << x[k] << endl;
        if(x[k] == 0) return;  
        // If k == n - 1 write x
        if(k == n - 1) {
            cout << num++ << ".) ";
            for(int i = 0; i <= n; i++)
                cout << x[i] << " ";
            cout << endl;
        }
        else hamiltonian(graph, n, k + 1, x);
    }
}

int main() {
    // vector<vector<int>> graph = { {0, 1, 0, 2},
    //                               {1, 0, 3, 0},
    //                               {0, 3, 0, 4},
    //                               {2, 0, 4, 0} };
    // vector<vector<int>> graph = { {0, 1, 1, 1},
    //                               {1, 0, 1, 1},
    //                               {1, 1, 0, 1},
    //                               {1, 1, 1, 0} };
                                // 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19
    vector<vector<int>> graph = { {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 0
                                  {1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 1
                                  {0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 2
                                  {0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 3
                                  {1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},  // 4
                                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0},  // 5
                                  {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},  // 6
                                  {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},  // 7
                                  {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},  // 8
                                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},  // 9
                                  {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},  // 10
                                  {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},  // 11
                                  {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},  // 12
                                  {0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},  // 13
                                  {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},  // 14
                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},  // 15
                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0},  // 16
                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},  // 17
                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},  // 18
                                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0} };// 19
    // Number of nodes in graph
    int n = 20;        
    // Visited vector
    int x[n + 1];
    for (int i = 0; i < n; i++)
        x[i] = 0;
    // Initial vertex
    x[0] = 0;
    x[n] = 0;
    // Start from vertex 0 and apply algorithm from vertex 1
    hamiltonian(graph, n, 1, x);
    
}