class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return calculate(nums, 0, 0, S);
    }
    
    int calculate(vector<int>& nums, int i, int sum, int S){
        if (i == nums.size()) {
            if (sum == S)
                return 1;
            return 0;
        } else {
          return calculate(nums, i + 1, sum + nums[i], S)
            + calculate(nums, i + 1, sum - nums[i], S);
        }
    }
};