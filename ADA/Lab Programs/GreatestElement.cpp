#include<iostream>
using namespace std;

int greatestI(int arr[], int n) {
    int gre = arr[0];
    for(int i = 1; i < n; i++)
        if(arr[i] > gre)
            gre = arr[i];
    return gre;
}

int greatestR(int arr[], int n) {

}

int main() {
    int arr[] = {43, 12, 34, 3, 5};
    cout << greatestI(arr, 5) << "\n";
    cout << greatestR(arr, arr[4], 5) << "\n";

    return 0;
}