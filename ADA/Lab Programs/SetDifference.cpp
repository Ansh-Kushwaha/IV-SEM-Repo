#include <iostream>
#include <vector>
using namespace std;

void diff(int arr1[], int arr2[], vector<int> &arr3, int m, int n) {
    bool flag;
    for(int i = 0; i < m; i++) {
        int curr = arr1[i];
        flag = false;
        for(int j = 0; j < n; j ++) {
            if(curr == arr2[j]) {
                flag = true;
                break;
            }
        }
        if(!flag)
            arr3.push_back(curr);
    }
}

int main() {
    int m = 5, n = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 6, 9};

    vector<int> arr3;
    diff(arr1, arr2, arr3, m, n);
    for(int i = 0; i < arr3.size(); i++)
        cout << arr3[i] << " ";
    cout << endl;

    return 0;
}