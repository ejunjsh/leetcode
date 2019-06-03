class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return lengthofLIS(nums, INT_MIN, 0);
    }
    
private:
     int lengthofLIS(vector<int>& nums, int prev, int curpos) {
        if (curpos == nums.size()) {
            return 0;
        }
        int taken = 0;
        if (nums[curpos] > prev) {
            taken = 1 + lengthofLIS(nums, nums[curpos], curpos + 1);
        }
        int nottaken = lengthofLIS(nums, prev, curpos + 1);
        return max(taken, nottaken);
    }
};