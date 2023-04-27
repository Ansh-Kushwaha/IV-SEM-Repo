#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int id;
    int profit;
    int weight;

    double proPWt;

    Item() {}

    Item(int i, int p, int w) {
        id = i;
        profit = p;
        weight = w;
        proPWt = (double) p / w;
    }
};

bool compareItems(Item i1, Item i2) {
    return i1.proPWt > i2.proPWt;
}

void greedyKnapsack(Item items[], int m, int n) {
    int orIdx[n];
    sort(items, items + n, compareItems);

    for(int i = 0; i < n; i++) {
        orIdx[i] = (items[i].id - 1);
        // cout << orIdx[i] << " " << items[i].proPWt << " ";
    }
    cout << endl;

    double result[n];

    for(int i = 0; i < n; i++)
        result[i] = 0.0;

    int u = m;
    double maxProfit = 0;
    int i;
    
    for(i = 0; i < n; i++) {
        if(items[i].weight > u)
            break;
        else {
            u = u - items[i].weight;
            maxProfit += items[i].profit;
            result[orIdx[i]] = 1;
        }
    }
    if(i != n) {
        result[orIdx[i]] = (double) u / items[i].weight;
        maxProfit += result[orIdx[i]] * items[i].profit;
    }
    
    cout << "\n[";
    for(int i = 0; i < n; i++) {
        cout << "x" << (i + 1) << " : " << result[i];
        if(i != n - 1)
            cout << ", ";
    }
    cout << "]" << endl;
    cout << "Maximum Profit : " << maxProfit << endl;
}

int main() {
    int m, n;
    cout << "Enter maximum capacity of Knapsack : ";
    cin >> m;
    cout << "Enter number of items : ";
    cin >> n;
    Item items[n];
    for(int i = 0; i < n; i++) {
        items[i].id = i + 1;
        cout << "Enter profit and weight of item " << (i + 1) << " : ";
        cin >> items[i].profit >> items[i].weight;
        items[i].proPWt = (double) items[i].profit / items[i].weight;
    }

    greedyKnapsack(items, m, n);

    return 0;
}