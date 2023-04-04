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
	if(n == 2) {
		*C = (*A * *B) + (*(A+(n/2)) * *(B+n));
		*(C+(n/2)) = (*A * *(B+(n/2))) + (*(A+(n/2)) * *(B+(2*n-1)));
		*(C+n) = (*(A+n) * *B) + (*(A+(2*n-1)) * *(B+n));
		*(C+(2*n-1)) = (*(A+n) * *(B+(n/2))) + (*(A+(2*n-1)) * *(B+(2*n-1)));
	}
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
		int P1[n / 2][n / 2];
		int P2[n / 2][n / 2];
		add(&A11[0][0], &A22[0][0], &P1[0][0], n / 2, n / 2);
		add(&B11[0][0], &B22[0][0], &P2[0][0], n / 2, n / 2);
		multiplyStrassen(&P1[0][0], &P2[0][0], &P[0][0], n / 2);

		// Q = (A21 + A22).B11
		int Q1[n / 2][n / 2];
		add(&A21[0][0], &A22[0][0], &Q1[0][0], n / 2, n / 2);
		multiplyStrassen(&Q1[0][0], &B11[0][0], &Q[0][0], n / 2);

		// R = A11.(B12 - B22)
		int R1[n / 2][n / 2];
		sub(&B12[0][0], &B22[0][0], &R1[0][0], n / 2, n / 2);
		multiplyStrassen(&A11[0][0], &R1[0][0], &R[0][0], n / 2);

		// S = A22.(B21 - B11)
		int S1[n / 2][n / 2];
		sub(&B21[0][0], &B11[0][0], &S1[0][0], n / 2, n / 2);
		multiplyStrassen(&A22[0][0], &S1[0][0], &S[0][0], n / 2);

		// T + (A11 + A12).B22
		int T1[n / 2][n / 2];
		add(&A11[0][0], &A12[0][0], &T1[0][0], n / 2, n / 2);
		multiplyStrassen(&T1[0][0], &B22[0][0], &T[0][0], n / 2);

		// U = (A21 - A11).(B11 + B12)
		int U1[n / 2][n / 2];
		int U2[n / 2][n / 2];
		sub(&A21[0][0], &A11[0][0], &U1[0][0], n / 2, n / 2);
		add(&B11[0][0], &B12[0][0], &U2[0][0], n / 2, n / 2);
		multiplyStrassen(&U1[0][0], &U2[0][0], &U[0][0], n / 2);

		// V = (A12 - A21).(B21 + B22)
		int V1[n / 2][n / 2];
		int V2[n / 2][n / 2];
		sub(&A12[0][0], &A21[0][0], &V1[0][0], n / 2, n / 2);
		add(&B21[0][0], &B22[0][0], &V2[0][0], n / 2, n / 2);
		multiplyStrassen(&V1[0][0], &V2[0][0], &V[0][0], n / 2);

		// C11 = P + S - T + V
		int C11[n / 2][n / 2];
		int C1[n / 2][n / 2];
		int C2[n / 2][n / 2];
		add(&P[0][0], &S[0][0], &C1[0][0], n / 2, n / 2);
		sub(&C1[0][0], &T[0][0], &C2[0][0], n / 2, n / 2);
		add(&C2[0][0], &V[0][0], &C11[0][0], n / 2, n / 2);

		// C12 = R + T
		int C12[n / 2][n / 2];
		add(&R[0][0], &T[0][0], &C12[0][0], n / 2, n / 2);

		// C21 = Q + S
		int C21[n / 2][n / 2];
		add(&Q[0][0], &S[0][0], &C21[0][0], n / 2, n / 2);

		// C22 = P + R - Q + U
		int C22[n / 2][n / 2];
		int C3[n / 2][n / 2];
		int C4[n / 2][n / 2];
		add(&P[0][0], &R[0][0], &C3[0][0], n / 2, n / 2);
		sub(&C3[0][0], &Q[0][0], &C4[0][0], n / 2, n / 2);
		add(&C4[0][0], &U[0][0], &C22[0][0], n / 2, n / 2);

		// Join 4 halves into one result matrix
		join(&C11[0][0], C, n / 2, n, 0, 0);
		join(&C12[0][0], C, n / 2, n, 0, n / 2);
		join(&C21[0][0], C, n / 2, n, n / 2, 0);
		join(&C22[0][0], C, n / 2, n, n / 2, n / 2);
	}
}

int main() {
	int n = 4;
	int A[n][n] = { { 1, 1, 1, 1 },
					{ 2, 2, 2, 2 },
					{ 3, 3, 3, 3 },
					{ 2, 2, 2, 2 } };
				
	int B[n][n] = { { 1, 1, 1, 1 },
					{ 2, 2, 2, 2 },
					{ 3, 3, 3, 3 },
					{ 2, 2, 2, 2 } };
	

	// int C[2][2] = { {0, 0}, {0, 0} };


	int C[n][n];
	multiplyStrassen(&A[0][0], &B[0][0], &C[0][0], n);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			cout << "\t" << C[i][j];
		cout << "\n";
	}
			
	return 0;
}