#include <iostream>
using namespace std;

void maxHeapify(int nums[], int n, int i) {
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if(leftChild < n && nums[leftChild] > nums[largest])
        largest = leftChild;
    if(rightChild < n && nums[rightChild] > nums[largest])
        largest = rightChild;
    
    if(largest != i) {
        int t = nums[largest];
        nums[largest] = nums[i];
        nums[i] = t;

        maxHeapify(nums, n, largest);
    }
}

void heapSort(int nums[], int n) {  // using MAX-Heap
    for(int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(nums, n, i);

    for(int i = n - 1; i > 0; i--) {
        int t = nums[0];
        nums[0] = nums[i];
        nums[i] = t;

        maxHeapify(nums, i, 0);
    }
}

int main() {
    int nums[] = {90, 2, 1, 45, 23, 5};
    heapSort(nums, 6);
    for(int i = 0; i < 6; i++)
        cout << nums[i] << " ";
    cout << "\n";

    return 0;
}