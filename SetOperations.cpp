#include <iostream>
#include <vector>
using namespace std;

void setUnion(int arrA[], int arrB[], int m, int n, vector<int> &uni) {
    
}

int main() {
    int m, n;
    int setA[m];
    int setB[n];

    cout << "Enter size of set A : ";
    cin >> m;

    cout << "Enter size of set B : ";
    cin >> n;

    for(int i = 0; i < m; i++)
        cin >> setA[i];

    for(int i = 0; i < n; i++)
        cin >> setB[i];

    bool flag = true;

    vector<int> uni;
    vector<int> inter;
    vector<int> diffA;
    vector<int> diffB;
    int comm;

    while(flag) {
        cout << "Enter operation to perform : \n";
        cout << "1 : Union" << endl;
        cout << "2 : intersection" << endl;
        cout << "3 : difference A-B" << endl;
        cout << "4 : difference B-A" << endl;
        cout << "5 : symmetric difference" << endl;
        cout << "6 : Exit" << endl;

        cin >> comm;
        if(comm == 1) {

        }
    }

    return 0;
}