class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i) {
            int _min = INT_MAX;
            int j = 1;
            while(i - j*j >= 0) {
                _min = min(_min, dp[i - j*j] + 1);
                ++j;
            }
            dp[i] = _min;
        }		
        return dp[n];
    }
};