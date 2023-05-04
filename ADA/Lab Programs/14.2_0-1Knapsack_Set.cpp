#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparePair(pair<int, int> p1, pair<int, int> p2) {
    return p1 > p2;
}

int knapsack(int m, int n, int pft[], int wt[]) {
    vector<vector<pair<int, int>>> S(n + 1);
    vector<vector<pair<int, int>>> S1(n);

    // S0 = {(0, 0)}
    S[0].push_back(make_pair(0, 0));

    for(int i = 1; i <= n; i++) {
        for(auto p : S[i - 1]) {
            S1[i - 1].push_back(make_pair(p.first + pft[i - 1], p.second + wt[i - 1]));
        }
        for(auto p : S[i - 1])
            S[i].push_back(p);
        for(auto p : S1[i - 1])
            S[i].push_back(p);
    }
    sort(S[S.size() - 1].begin(), S[S.size() - 1].end(), comparePair);
    for(auto p : S[S.size() - 1])
        if(p.second <= m)
            return p.first;
    return -1;
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