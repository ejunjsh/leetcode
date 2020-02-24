class Solution {
public:
    int fib(int N) {
         if (N <= 1) {
          return N;
        }
        
        vector<vector<int>> A={{1, 1}, {1, 0}};
        
        matrixPower(A, N-1);

        return A[0][0];
    }
    
    void matrixPower(vector<vector<int>>& A, int N) {
        if (N <= 1) {
          return;
        }
        matrixPower(A, N/2);
        multiply(A, A);

        vector<vector<int>> B={{1, 1}, {1, 0}};
        if (N%2 != 0) {
            multiply(A, B);
        }
    }
    
     void multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int x = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        int y = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        int z = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        int w = A[1][0] * B[0][1] + A[1][1] * B[1][1];

        A[0][0] = x;
        A[0][1] = y;
        A[1][0] = z;
        A[1][1] = w;
    }
};