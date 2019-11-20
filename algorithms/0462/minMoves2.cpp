class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res = 0, n = nums.size(), mid = n / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        for (int i = 0; i < n; ++i) {
            res += abs(nums[i] - nums[mid]);
        }
        return res;
    }
};