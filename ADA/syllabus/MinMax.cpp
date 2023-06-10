#include <iostream>
using namespace std;

void MinMax(int arr[], int &min, int &max, int i, int j) {
    if(i == j)
        min = max = arr[i];
    else if(i == j - 1) {
        if(arr[i] > arr[j]) {
            min = arr[j];
            max = arr[i];
        }
        else {
            min = arr[i];
            max = arr[j];
        }
    }
    else {
        int mid = (i + j) / 2;
            int minL, minR, maxL, maxR;
        MinMax(arr, minL, maxL, i, mid);
        MinMax(arr, minR, maxR, mid + 1, j);
        
        max = (maxL > maxR) ? maxL : maxR;
        min = (minL < minR) ? minL : minR;
    }
}

int main() {
    int arr[] = {10, 2, 3, 11, 4, 8};
    int min, max;
    MinMax(arr, min, max, 0, 5);
    cout << min << " " << max << endl;

}