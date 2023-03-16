#include <iostream>
using namespace std;

void merge(int arr[], int s, int mid, int e) {
    cout << "Merge(" << s << ", " << mid << ", " << e << ")\n";
    int l = mid - s + 1;
    int r = e - mid;

    int L[l];
    int R[r];

    for(int i = 0; i < l; i++)
        L[i] = arr[s + i];
    for(int j = 0; j < r; j++)
        R[j] = arr[mid + j + 1];

    // merge part
    int i = 0, j = 0, k = s;
    while(i < l && j < r) {
        if(L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while(i < l)
        arr[k++] = L[i++];
    
    while(j < r)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int s, int e) {
    if(s < e) {
        cout << "MergeSort(" << s << ", " << e << ")\n";
        int mid = (s + e) / 2;

        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
}

int main() {
    int nums[] = {90, 2, 1, 45, 23, 5};
    mergeSort(nums, 0, 5);
    for(int i = 0; i < 6; i++)
        cout << nums[i] << " ";
    cout << "\n";

    return 0;
}