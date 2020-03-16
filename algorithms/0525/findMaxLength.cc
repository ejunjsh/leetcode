class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         int maxlen = 0;
        for (int start = 0; start < nums.size(); start++) {
            int zeroes = 0, ones = 0;
            for (int end = start; end < nums.size(); end++) {
                if (nums[end] == 0) {
                    zeroes++;
                } else {
                    ones++;
                }
                if (zeroes == ones) {
                    maxlen = max(maxlen, end - start + 1);
                }
            }
        }
        return maxlen;
    }
};