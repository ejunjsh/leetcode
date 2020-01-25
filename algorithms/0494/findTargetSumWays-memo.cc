class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> memo(nums.size(),vector<int>(2001,INT_MIN));
        return calculate(nums, 0, 0, S, memo);
    }
    
    int calculate(vector<int>& nums, int i, int sum, int S, vector<vector<int>>& memo) {
        if (i == nums.size()) {
            if (sum == S)
                return 1;
            else
                return 0;
        } else {
            if (memo[i][sum + 1000] != INT_MIN) {
                return memo[i][sum + 1000];
            }
            int add = calculate(nums, i + 1, sum + nums[i], S, memo);
            int subtract = calculate(nums, i + 1, sum - nums[i], S, memo);
            memo[i][sum + 1000] = add + subtract;
            return memo[i][sum + 1000];
        }
    }
};