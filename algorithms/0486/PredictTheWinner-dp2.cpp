class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        for (int s = nums.size(); s >= 0; s--) {
            for (int e = s + 1; e < nums.size(); e++) {
                int a = nums[s] - dp[e];
                int b = nums[e] - dp[e - 1];
                dp[e] = max(a, b);
            }
        }
        return dp[nums.size() - 1] >= 0;
    }
};