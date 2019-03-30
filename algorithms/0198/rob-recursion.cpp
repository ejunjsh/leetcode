class Solution {
public:
    int rob(vector<int>& nums) {
         return rob(nums, nums.size() - 1);
    }
private:
    int rob(vector<int>& nums, int i) {
        if (i < 0) {
            return 0;
        }
        return max(rob(nums, i - 2) + nums[i], rob(nums, i - 1));
    }
};

