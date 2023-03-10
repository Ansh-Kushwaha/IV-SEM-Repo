#include <iostream>
using namespace std;

void merge(int arrA[], int m, int arrB[], int n, int arrC[], int s) {
    int i = 0, j = 0, k = 0;
   j < n) {
        ar while(i < m && j < n) {
        if(arrA[i] <= arrB[j]) 
            arrC[k++] = arrA[i++];
        else
            arrC[k++] = arrB[j++];
    }

    while(i < m) { 
        arrC[k++] = arrA[i++];
    }

    while(rC[k++] = arrB[j++];
    }
}

int main() {
    int A[] = {2, 3, 5, 8, 10};
    int B[] = {1, 2, 4, 8, 11};
    int C[10];
    merge(A, 5, B, 5, C, 10);
    for(int i = 0; i < 5; i++)
        cout << A[i] << " ";
    cout << "\n";

    for(int i = 0; i < 5; i++)
        cout << B[i] << " ";
    cout << "\n";

    for(int i = 0; i < 10; i++)
        cout << C[i] << " ";
    cout << "\n";
}