class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0, n = nums.size();
        unsigned int mask=1;
        for (int i = 0;i < 32; i++) {
            int bitCounts = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask) bitCounts++;
                if (bitCounts > n / 2) {
                    major |= mask;
                    break;
                }
            }
            mask <<= 1;
        } 
        return major;
    } 
};