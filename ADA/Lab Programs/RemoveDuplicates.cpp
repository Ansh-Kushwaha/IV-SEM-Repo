#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

void shiftLeft(int arr[], int s, int e) {
    for(int i = s; i < e; i++) {
        swap(arr[i], arr[i + 1]);
    }
}

int main() {
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    // Example 1 2 9 8 2 2 3 9
    // Answer 1 2 9 8 3
    int newSize = n;

    for(int i = 0; i < n - 1; i++) {
        int curr = arr[i];
        for(int j = i + 1; j < n; j++) {
            if(arr[j] == curr) {
                newSize--;
                if(j != n - 1) {
                    shiftLeft(arr, j, n - 1);
                    n--;
                    i--; // Rechecking
                }
            }
        }
    }

    for(int i = 0; i < newSize; i++)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;    
}