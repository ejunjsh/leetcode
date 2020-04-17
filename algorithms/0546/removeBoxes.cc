class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[100][100][100] = {0};
        return dfs(boxes, 0, n - 1, 0, dp);
    }
    int dfs(vector<int>& boxes, int i, int j, int k, int dp[100][100][100]) {
        if (j < i) return 0;
        if (dp[i][j][k] > 0) return dp[i][j][k];
        int res = (1 + k) * (1 + k) + dfs(boxes, i + 1, j, 0, dp);
        for (int m = i + 1; m <= j; ++m) {
            if (boxes[m] == boxes[i]) {
                res = max(res, dfs(boxes, i + 1, m - 1, 0, dp) + dfs(boxes, m, j, k + 1, dp));
            }
        }
        return dp[i][j][k] = res;
    }
};
