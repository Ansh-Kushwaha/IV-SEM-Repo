import java.util.Arrays;
public class StrassenMultiplication {
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

    public int[][] multiply(int[][] A, int[][] B) {
        int n = A.length;        
        int[][] C = new int[n][n];

        if(n == 1) {
            C[0][0] = A[0][0] * B[0][0];
        }
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

            // Using formulas as described in algorithm
            // P = (A11 + A22) × (B11 + B22)
            int[][] P = multiply(add(A11, A22), add(B11, B22));
            
            // Q = (A21 + A22) x B11
            int[][] Q = multiply(add(A21, A22), B11);
           
            // R = A11 x (B12 - B22)
            int[][] R = multiply(A11, sub(B12, B22));
           
            // S = A22 × (B21 − B11)
            int[][] S = multiply(A22, sub(B21, B11));
           
            // T = (A11 + A12) x B22
            int[][] T = multiply(add(A11, A12), B22);
           
            // U = (A21 - A11) x (B11 + B12)
            int[][] U = multiply(sub(A21, A11), add(B11, B12));
           
            // V = (A12 - A21) x (B21 + B22)
            int[][] V = multiply(sub(A12, A22), add(B21, B22));
 
            // C11 = P + S - T + V
            int[][] C11 = add(sub(add(P, S), T), V);
           
            // C12 = R + T
            int[][] C12 = add(R, T);
           
            // C21 = Q + S
            int[][] C21 = add(Q, S);
           
            // C22 = P + R - Q + U
            int[][] C22 = add(sub(add(P, R), Q), U);

            // Step 3: Join 4 halves into one result matrix
            join(C11, C, 0, 0);
            join(C12, C, 0, n / 2);
            join(C21, C, n / 2, 0);
            join(C22, C, n / 2, n / 2);

        }
        return C;
    }

    public static void main(String[] args) {
        int[][] A = { { 1, 1, 1, 1 },
                      { 2, 2, 2, 2 },
                      { 3, 3, 3, 3 },
                      { 2, 2, 2, 2 } };
                      
        int[][] B = { { 1, 1, 1, 1 },
                      { 2, 2, 2, 2 },
                      { 3, 3, 3, 3 },
                      { 2, 2, 2, 2 } };
        
        StrassenMultiplication s = new StrassenMultiplication();

        int[][] C = s.multiply(A, B);

        for(int i = 0; i < C.length; i++) {
            for(int j = 0; j < C.length; j++) {
                System.out.print("\t" + C[i][j]);
            }
            System.out.println();
        }
    }
}