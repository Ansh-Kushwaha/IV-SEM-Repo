#include <iostream>
using namespace std;

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
    int nums[] = {1, 2, 5, 23, 45, 90};
    cout << binSearchI(nums, 90, 0, 5) <<"\n";
    cout << binSearchR(nums, 23, 0, 5) <<"\n";

    return 0;
}