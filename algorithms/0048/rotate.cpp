class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2 + n % 2; i++) {
          for (int j = 0; j < n / 2; j++) {
            int tmp[4];
            int row = i;
            int col = j;
            for (int k = 0; k < 4; k++) {
              tmp[k] = matrix[row][col];
              int x = row;
              row = col;
              col = n - 1 - x;
            }
            for (int k = 0; k < 4; k++) {
              matrix[row][col] = tmp[(k + 3) % 4];
              int x = row;
              row = col;
              col = n - 1 - x;
            }
          }
        }
    }
};