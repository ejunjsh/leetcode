class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n] = {0};
        dp[0] = nums[0];
        int r = dp[0];
        
        for(int i = 1; i < n; i++){
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            r = max(r, dp[i]);
        }
        
        return r;
    }
};