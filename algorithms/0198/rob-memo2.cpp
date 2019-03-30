class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> memo(nums.size()+1,0);
        memo[0] = 0;
        memo[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int val = nums[i];
            memo[i+1] = max(memo[i], memo[i-1] + val);
        }
        return memo[nums.size()];
    }
};
 