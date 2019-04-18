class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
        vector<int> dp(cols+1,0);
        int maxsqlen = 0, prev=0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                int temp = dp[j];
                if (matrix[i-1][j-1] == '1'){
                    dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), prev) + 1;
                    maxsqlen = max(maxsqlen, dp[i][j]);
                } else{
                    dp[j]=0;
                }
                prev = temp;
            }
        }
        return maxsqlen * maxsqlen;
    }
};