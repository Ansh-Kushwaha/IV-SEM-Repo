#include<iostream>
using namespace std;

struct Item {
    int profit;
    int weight;

    Item(int p, int w) {
        profit = p;
        weight = w;
    }
};

bool compareItems(Item i1, Item i2) {
    double p1 = (double) i1.profit / i1.weight;
    double p2 = (double) i2.profit / i2.weight;
    return p1 > p2;
}

void greedyKnapsack(Item items[], int m, int n) {
    int sortedIdx[n];
    bool s[n];
    for(int i = 0; i < n; i++)
        s[i] = false;
    for(int i = 0; i < n; i++) {
        int maxIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(compareItems(items[j], items[i]))
                maxIdx = j;
        }
        if(!s[maxIdx]) {
            sortedIdx[i] = maxIdx;
            s[maxIdx] = true;
        }

    }

    for(int i = 0; i < n; i++)
        cout << sortedIdx[i] << " ";
    cout << endl;

    double result[n];
    for(int i = 0; i < n; i++)
        result[i] = 0.0;

    int u = m;
    int i;
    for(i = 0; i < n; i++) {
        if(items[sortedIdx[i]].weight > u)
            break;
        else {
            u = u - items[sortedIdx[i]].weight;
            result[sortedIdx[i]] = 1;
        }
    }
    if(i != n)
        result[sortedIdx[i]] = (double) u / items[i].weight;
    
    cout << "[";
    for(int i = 0; i < n; i++) {
        cout << "x" << (i + 1) << " : " << result[sortedIdx[i]];
        if(i != n - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    int m = 20;
    Item items[] = { {10, 15},
                     {20, 15},
                     {30, 10} };
    int n = sizeof(items) / sizeof(items[0]);
    greedyKnapsack(items, m, n);

    return 0;
}