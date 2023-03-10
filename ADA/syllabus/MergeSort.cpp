#include <iostream>
using namespace std;

void merge(int arr[], int s, int mid, int e) {
    int lSize = mid - s + 1;
    int rSize = e - mid;

    int lArr[lSize];
    int rArr[rSize];

    for(int i = 0; i < lSize; i++)
        lArr[i] = arr[s + i];
    for(int j = 0; j < rSize; j++)
        rArr[j] = arr[mid + j + 1];

    // merge part
    int i = 0, j = 0, k = s;
    while(i < lSize && j < rSize) {
        if(lArr[i] <= rArr[j])
            arr[k++] = lArr[i++];
        else
            arr[k++] = rArr[j++];
    }

    while(i < lSize)
        arr[k++] = lArr[i++];
    
    while(j < rSize)
        arr[k++] = rArr[j++];
}

void mergeSort(int arr[], int s, int e) {
    if(s < e) {
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