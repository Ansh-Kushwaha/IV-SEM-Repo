#include <iostream>
using namespace std;

int max(int a, int b) {
    return (a >= b ? a : b);
}

int knapsack(int m, int n, int pft[], int wt[]) {
    int T[n + 1][m + 1]; // DP Table number of items x maximum weight

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= m; w++) {
            // If weight of item or current capacity of knapsack is 0
            if(i == 0 || w == 0)
                T[i][w] = 0;
            // If weight of current item is less than max. capacity of knapsack (currently)
            else if(wt[i - 1] <= w) {
                // To add item i or not based on max. profit earned
                T[i][w] = max(pft[i - 1] + T[i - 1][w - wt[i - 1]], T[i - 1][w]);
            }
            // If weight of current item is greater than max. capacity of knapsack (currently)
            else {
                // Copy the value from last row 
                T[i][w] = T[i - 1][w];
            }
        }
    }

    // For reference
    /*
    for(int i = 0; i <= n; i++) {
        cout << "\n";
        for(int j = 0; j <= m; j++)
            cout << T[i][j] << " ";
    }
    */

    return T[n][m];
    
}

int main() {
    int m, n;
    cout << "Enter maximum capacity of Knapsack : ";
    cin >> m;
    cout << "Enter number of items : ";
    cin >> n;
    int weight[n], profit[n];

    for(int i = 0; i < n; i++) {
        cout << "Enter profit and weight of item " << (i + 1) << " : ";
        cin >> profit[i] >> weight[i];
    }

    cout << "Maximum profit earned : " << knapsack(m, n, profit, weight) << endl;

    return 0;
}