class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        return 1 + max(calculate(nums, 0, true), calculate(nums, 0, false));
    }
    
private:
    int calculate(vector<int>& nums, int index, bool isUp) {
        int maxcount = 0;
        for (int i = index + 1; i < nums.size(); i++) {
            if ((isUp && nums[i] > nums[index]) || (!isUp && nums[i] < nums[index]))
                maxcount = max(maxcount, 1 + calculate(nums, i, !isUp));
        }
        return maxcount;
    }
};