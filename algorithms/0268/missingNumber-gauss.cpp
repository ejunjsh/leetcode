class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expectedSum = nums.size()*(nums.size() + 1)/2;
        int actualSum = 0;
        for (int num : nums) actualSum += num;
        return expectedSum - actualSum;
    }
};