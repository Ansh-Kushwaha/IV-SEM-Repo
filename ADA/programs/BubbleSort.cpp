#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool flag;
    int nSwaps = 0;
    int nPasses = 0;
    for(int i = 0; i < n - 1; i++) {
        nPasses++;
        flag = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                nSwaps++;
                flag = true;
            }
        }
            if(!flag)
                break;
    }
    cout << "Total Passes : " << nPasses << endl;
    cout << "Total swapping : " << nSwaps << endl;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >>  arr[i];

    bubbleSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}