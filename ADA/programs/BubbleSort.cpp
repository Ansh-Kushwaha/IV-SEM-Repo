#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {4, 1, 3, 5, 12, 4, 4};
    bubbleSort(arr, 7);
    for(int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    cout << "\n";
}