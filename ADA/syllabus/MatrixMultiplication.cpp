#include <bits/stdc++.h>
using namespace std;


// Basic O(n^3) algorithm
void multiply(vector<vector<int>> &matA, vector<vector<int>> &matB, vector<vector<int>> &matC) {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            int sum = 0;
            for(int k = 0; k < 2; k++) {
                sum += matA[i][k] * matB[k][j]; 
            }
            matC[i][j] = sum;
        }
    }
}

// Strassen's matrix multiplication

int main() {
    vector<vector<int>> matA = {{1, 2}, {3, 4}};
    vector<vector<int>> matB = {{4, 3}, {2, 1}};
    vector<vector<int>> matC(2, vector<int>(2));

    multiply(matA, matB, matC);

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << matC[i][j] << " ";
        }
        cout << "\n";
    }
}