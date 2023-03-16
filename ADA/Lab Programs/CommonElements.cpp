#include <iostream>
#include <vector>
using namespace std;

void common(int arr1[], int arr2[], vector<int> &arr3, int m, int n) {
    for(int i = 0; i < m; i++) {
        int curr = arr1[i];
        for(int j = 0; j < n; j ++) {
            if(curr == arr2[j]) {
                arr3.push_back(curr);
                break;
            }
        }
    }
}

int main() {
    int m = 5, n = 5;
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 6, 9};

    vector<int> arr3;
    common(arr1, arr2, arr3, m, n);
    for(int i = 0; i < arr3.size(); i++)
        cout << arr3[i] << " ";
    cout << endl;

    return 0;
}