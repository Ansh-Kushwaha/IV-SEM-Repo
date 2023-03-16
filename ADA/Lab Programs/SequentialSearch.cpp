// 02/03/2023

#include <iostream>
using namespace std;

int seqSearch(int arr[], int size, int x) {    
    for(int i = 0; i < size; i++)
        if(arr[i] == x)
            return i;
    return -1;
}

int main() {
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int x;
    cout << "Enter the number you want to search : ";
    cin >> x;

    int idx = seqSearch(arr, n, x);
    if(idx == -1)
        cout << "Not found.\n";
    else
        cout << "Found at index " << idx << "\n";
    return 0;
}