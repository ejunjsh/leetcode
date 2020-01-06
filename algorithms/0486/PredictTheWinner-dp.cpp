class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size(),0));
        for (int s = nums.size(); s >= 0; s--) {
            for (int e = s + 1; e < nums.size(); e++) {
                int a = nums[s] - dp[s + 1][e];
                int b = nums[e] - dp[s][e - 1];
                dp[s][e] = max(a, b);
            }
        }
        return dp[0][nums.size() - 1] >= 0;
    }
};
