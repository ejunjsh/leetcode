class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(),vector<int>(nums.size(),0));
        return winner(nums, 0, nums.size() - 1, memo) >= 0;
    }
    
    int winner(vector<int>& nums, int s, int e, vector<vector<int>>& memo) {
        if (s == e)
            return nums[s];
        if (memo[s][e] != NULL)
            return memo[s][e];
        int a = nums[s] - winner(nums, s + 1, e, memo);
        int b = nums[e] - winner(nums, s, e - 1, memo);
        memo[s][e] = max(a, b);
        return memo[s][e];
    }
};