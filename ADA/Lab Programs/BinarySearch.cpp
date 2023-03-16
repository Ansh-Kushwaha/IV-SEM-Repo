#include<iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;

}

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;
    
    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i) {
        swap(arr[largest], arr[i]);

        maxHeapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for(int i = n - 1; i > 0; i--) {
        swap(arr[0],  arr[i]);

        maxHeapify(arr, i, 0);
    }
}


int binSearchI(int arr[], int x, int s, int e) {
    while(s <= e) {
        int mid = (s + e) / 2;

        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int binSearchR(int arr[], int x, int s, int e) {
    if(s <= e) {
        int mid = (s + e) / 2;

        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            return binSearchR(arr, x, s, mid - 1);
        else
            return binSearchR(arr, x, mid + 1, e);
    }
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

    heapSort(arr, n);

    cout << "Sorted array : ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";

    cout << "Enter the number you want to search : ";
    cin >> x;

    
    int idx = binSearchR(arr, x, 0, n-1);

    if(idx == -1)
        cout << "Not found.\n";
    else
        cout << "Found at index " << idx << "\n";
    return 0;
}