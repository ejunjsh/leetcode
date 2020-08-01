class Solution {
public:
    int M = 1000000007;
    
    int findPaths(int m, int n, int N, int i, int j) {
        vector<vector<vector<int>>> memo(m,vector<vector<int>>(n, vector<int>(N+1, -1)) );
        return findPaths(m, n, N, i, j, memo);
    }
    
    int findPaths(int m, int n, int N, int i, int j,vector<vector<vector<int>>>& memo) {
    if (i == m || j == n || i < 0 || j < 0) return 1;
    if (N == 0) return 0;
    if (memo[i][j][N] >= 0) return memo[i][j][N];
    memo[i][j][N] = (
        (findPaths(m, n, N - 1, i - 1, j, memo) + findPaths(m, n, N - 1, i + 1, j, memo)) % M +
        (findPaths(m, n, N - 1, i, j - 1, memo) + findPaths(m, n, N - 1, i, j + 1, memo)) % M
    ) % M;
    return memo[i][j][N];
  }
};