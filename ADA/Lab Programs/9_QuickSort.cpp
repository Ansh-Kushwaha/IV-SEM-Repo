#include <iostream>
using namespace std;

// int partition(int arr[], int low, int high) { // Lomuto Partition
//     int pivot = arr[high];
//     int idx = low - 1;
//     for(int i = low; i < high; i++) {
//         if(arr[i] < pivot) {
//             idx++;
//             int t = arr[i];
//             arr[i] = arr[idx];
//             arr[idx] = t;
//         }
//     }
//     int temp = arr[idx + 1];
//     arr[idx + 1] = arr[high];
//     arr[high] = temp;
//     return idx + 1;
// }

int stepCount;

int partition(int arr[], int low, int high) { // Hoare's Partition 3x less swaps
    int pivot = arr[low]; stepCount++;
    int i = low, j = high; stepCount++;

    while(i < j) {
        while(arr[i] <= pivot && i < high)
            i++; stepCount++;
       
        while(arr[j] > pivot)
            j--; stepCount++;

        if(i < j) { stepCount++;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }      
    }
    
    stepCount++;
    arr[low] = arr[j];
    arr[j] = pivot;

    stepCount++;
    return j;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high); stepCount++;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    stepCount = 0;
    int nums[] = {90, 2, 1, 45, 23, 5};
    quickSort(nums, 0, 5);
    for(int i = 0; i < 6; i++)
        cout << nums[i] << " ";
    cout << "\n";
    cout << "Total steps : " << stepCount << "\n";

    return 0;
}