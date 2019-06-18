class Solution {
public:
    int maxCoins(vector<int> &iNums) {
        int nums[iNums.size() + 2];
        int n = 1;
        for (int x : iNums) if (x > 0) nums[n++] = x;
        nums[0] = nums[n++] = 1;


        int dp[n][n] = {};
        for (int k = 2; k < n; ++k) {
            for (int l = 0; l < n - k; ++l){
                int r = l + k;
                for (int i = l + 1; i < r; ++i){
                    dp[l][r] = max(dp[l][r],
                         nums[l] * nums[i] * nums[r] + dp[l][i] + dp[i][r]);
                }
            }
        }

        return dp[0][n - 1];
    }
};