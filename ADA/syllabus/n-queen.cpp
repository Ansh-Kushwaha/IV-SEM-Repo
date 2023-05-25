#include <iostream>
using namespace std;

bool place(int k, int i, int x[]) {
    for(int j = 0; j < k - 1; j++) {
        if(x[j] == i + 1 || abs(x[j] - (i + 1)) == abs(j - (k - 1))) {
            return false;
        }
    }
    return true;
}

void nQueen(int k, int n, int x[]) {
    // For each column
    for(int i = 0; i < n; i++) {
        // If the kth queen can be placed in ith column
        if(place(k, i, x)) {
            x[k - 1] = i + 1;
            // If all queens have been placed
            if(k == n) {
                // Write x
                cout << "x: ";
                for(int i = 0; i < n; i++)
                    cout << x[i] << " ";
                cout << endl;
            }
            // Else place the next queen
            else
                nQueen(k + 1, n, x);
        }
    }
}

int main() {
    // Size of board
    int n = 32;
    // Array to store the position of queens
    int x[n];
    nQueen(1, n, x);

    return 0;
}