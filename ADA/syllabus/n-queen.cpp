#include <iostream>
using namespace std;

bool place(int k, int i, int x[]) {
    for(int j = 1; j < k; j++) {
        if(x[j - 1] == i || abs(x[j - 1] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void nQueen(int k, int n, int x[]) {
    // For each column
    for(int i = 0; i < n; i++) {
        // If the kth queen can be placed in ith column
        if(place(k, i + 1, x)) {
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
    int n = 8;
    // Array to store the position of queens
    int x[n];
    nQueen(1, n, x);

    return 0;
}