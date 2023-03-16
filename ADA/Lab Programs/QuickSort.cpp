#include <iostream>
using namespace std;

int partition(int arr[], int s, int e) {
    int pivot = arr[e];
    int idx = s - 1;
    for(int i = s; i < e; i++) {
        if(arr[i] < pivot) {
            idx++;
            int t = arr[i];
            arr[i] = arr[idx];
            arr[idx] = t;
        }
    }
    int temp = arr[idx + 1];
    arr[idx + 1] = arr[e];
    arr[e] = temp;
    return idx + 1;
}

void quickSort(int arr[], int s, int e) {
    if(s < e) {
        int pi = partition(arr, s, e);

        quickSort(arr, s, pi - 1);
        quickSort(arr, pi + 1, e);
    }
}

int main() {
    int nums[] = {90, 2, 1, 45, 23, 5};
    quickSort(nums, 0, 5);
    for(int i = 0; i < 6; i++)
        cout << nums[i] << " ";
    cout << "\n";

    return 0;
}