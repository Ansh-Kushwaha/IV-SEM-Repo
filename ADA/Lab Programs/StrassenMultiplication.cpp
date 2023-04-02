#include <iostream>
using namespace std;

void add(int* mat1, int* mat2, int* mat3, int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			*(mat3+(i*n+j)) = *(mat1+(i*n+j)) + *(mat2+(i*n+j));
		}
	}
}

void sub(int* mat1, int* mat2, int *mat3, int m, int n) {
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			*(mat3+(i*n+j)) = *(mat1+(i*n+j)) - *(mat2+(i*n+j));
		}
	}
}

void split(int* A, int* partA, int s, int partS, int i, int j) {
    for(int i1 = 0, i2 = i; i1 < partS; i1++, i2++)
        for(int j1 = 0, j2 = j; j1 < partS; j1++, j2++)
            *(partA+(i1*partS+j1)) = *(A+(i2*s+j2));
}

void join(int* partA, int* A, int partS, int s, int i, int j) {
    for(int i1 = 0, i2 = i; i1 < partS; i1++, i2++)
        for(int j1 = 0, j2 = j; j1 < partS; j1++, j2++)
            *(A+(i2*s+j2)) = *(partA+(i1*partS+j1));
}

void multiplyStrassen(int* A, int* B, int* C, int n) {
    if(n == 1)
        *C = *A + *B;
    else {
        // Divide the matrix into parts
        int A11[n / 2][n / 2];
        int A12[n / 2][n / 2];
        int A21[n / 2][n / 2];
        int A22[n / 2][n / 2];
        int B11[n / 2][n / 2];
        int B12[n / 2][n / 2];
        int B21[n / 2][n / 2];
        int B22[n / 2][n / 2];

        // Split the matices A and B into 4 halves
        split(A, &A11[0][0], n, n / 2, 0, 0);
        split(A, &A12[0][0], n, n / 2, 0, n / 2);
        split(A, &A21[0][0], n, n / 2, n / 2, 0);
        split(A, &A22[0][0], n, n / 2, n / 2, n / 2);

        split(A, &B11[0][0], n, n / 2, 0, 0);
        split(A, &B12[0][0], n, n / 2, 0, n / 2);
        split(A, &B21[0][0], n, n / 2, n / 2, 0);
        split(A, &B22[0][0], n, n / 2, n / 2, n / 2);

        // Using formulas as described in algorithm
        int P[n / 2][n / 2];
        int Q[n / 2][n / 2];
        int R[n / 2][n / 2];
        int S[n / 2][n / 2];
        int T[n / 2][n / 2];
        int U[n / 2][n / 2];
        int V[n / 2][n / 2];

        // P = (A11 + A22).(B11 + B22)
        int p1[n / 2][n / 2];

    }
    
}

int main() {
    int A[4][4] = { {1, 2},
                    {1, 2} };
                
    int B[2][2] = { {0, 2},
                    {1, 3} };
    

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            cout << "\t" << A[i][j];
        }
        cout << "\n";
    }

    return 0;
}


