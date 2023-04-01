public class StrassenMulti {
    public int[][] add(int[][] A, int[][] B) {
        int n = A.length;
        int[][] C = new int[n][n];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                C[i][j] = A[i][j] + B[i][j];
        
        return C;
    }

    public int[][] sub(int[][] A, int[][] B) {
        int n = A.length;
        int[][] C = new int[n][n];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                C[i][j] = A[i][j] - B[i][j];
        
        return C;
    }

    public void split(int[][] A, int[][] AP, int i, int j) {
        for(int i1 = 0, i2 = i; i1 < AP.length; i1++, i2++)
            for(int j1 = 0, j2 = j; j1 < AP.length; j1++, j2++)
                AP[i1][j1] = A[i2][j2];
    }

    public void join(int[][] CP, int[][] C, int i, int j) {
        for (int i1 = 0, i2 = i; i1 < CP.length; i1++, i2++)
            for (int j1 = 0, j2 = j; j1 < CP.length; j1++, j2++)
                C[i2][j2] = CP[i1][j1];
    }

    public int[][] multiplyS(int[][] A, int[][] B) {
        int n = A.length;
        int[][] R = new int[n][n];

        if(n == 1)
            R[0][0] = A[0][0] * B[0][0];
        else {
            // Setp 1 divide the matrix into parts
            int[][] A11 = new int[n / 2][n / 2];
            int[][] A12 = new int[n / 2][n / 2];
            int[][] A21 = new int[n / 2][n / 2];
            int[][] A22 = new int[n / 2][n / 2];
            int[][] B11 = new int[n / 2][n / 2];
            int[][] B12 = new int[n / 2][n / 2];
            int[][] B21 = new int[n / 2][n / 2];
            int[][] B22 = new int[n / 2][n / 2];

            // Split the matices A and B into 4 halves
            split(A, A11, 0, 0);
            split(A, A12, 0, n / 2);
            split(A, A21, n / 2, 0);
            split(A, A22, n / 2, n / 2);

            split(B, B11, 0, 0);
            split(B, B12, 0, n / 2);
            split(B, B21, n / 2, 0);
            split(B, B22, n / 2, n / 2);

            // Using Formulas as described in algorithm
 
            // M1:=(A1+A3)×(B1+B2)
            int[][] M1 = multiplyS(add(A11, A22), add(B11, B22));
           
            // M2:=(A2+A4)×(B3+B4)
            int[][] M2 = multiplyS(add(A21, A22), B11);
           
            // M3:=(A1−A4)×(B1+A4)
            int[][] M3 = multiplyS(A11, sub(B12, B22));
           
            // M4:=A1×(B2−B4)
            int[][] M4 = multiplyS(A22, sub(B21, B11));
           
            // M5:=(A3+A4)×(B1)
            int[][] M5 = multiplyS(add(A11, A12), B22);
           
            // M6:=(A1+A2)×(B4)
            int[][] M6 = multiplyS(sub(A21, A11), add(B11, B12));
           
            // M7:=A4×(B3−B1)
            int[][] M7 = multiplyS(sub(A12, A22), add(B21, B22));
 
            // P:=M2+M3−M6−M7
            int[][] C11 = add(sub(add(M1, M4), M5), M7);
           
            // Q:=M4+M6
            int[][] C12 = add(M3, M5);
           
            // R:=M5+M7
            int[][] C21 = add(M2, M4);
           
            // S:=M1−M3−M4−M5
            int[][] C22 = add(sub(add(M1, M3), M2), M6);

            // Step 3: Join 4 halves into one result matrix
            join(C11, R, 0, 0);
            join(C12, R, 0, n / 2);
            join(C21, R, n / 2, 0);
            join(C22, R, n / 2, n / 2);

        }
        return R;
    }

    public static void main(String[] args) {
        int[][] A = { {1, 2},
                      {2, 1} };
        int[][] B = { {2, 2},
                      {2, 2} };
        
        StrassenMulti s = new StrassenMulti();

        int[][] C = s.multiplyS(A, B);

        for(int i = 0; i < C.length; i++) {
            for(int j = 0; j < C.length; j++) {
                System.out.print(C[i][j] + " ");
            }
            System.out.println();
        }
    }
}