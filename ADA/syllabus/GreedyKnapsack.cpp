#include <iostream>
using namespace std;

struct Item {
    int id;
    int profit;
    int weight;

    double proPWt;

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
    for(int i = 0; i < n; i++) {
        int maxIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(compareItems(items[j], items[i]))
                maxIdx = j;
        }
        if(maxIdx != i) {
            Item temp = items[i];
            items[i] = items[maxIdx];
            items[maxIdx] = temp;
        }
    }

    for(int i = 0; i < n; i++) 
        orIdx[i] = (items[i].id - 1);

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
    
    cout << "[";
    for(int i = 0; i < n; i++) {
        cout << "x" << (i + 1) << " : " << result[i];
        if(i != n - 1)
            cout << ", ";
    }
    cout << "]" << endl;
    cout << "Maximum Profit : " << maxProfit << endl;
}

int main() {
    int m = 20;
    Item items[] = { {1, 10, 15},
                     {2, 20, 15},
                     {3, 30, 10} };
    int n = sizeof(items) / sizeof(items[0]);
    greedyKnapsack(items, m, n);

    return 0;
}