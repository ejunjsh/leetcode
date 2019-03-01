class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0], n = nums.size();
        int f = nums[0];
        int g = nums[0];
        for (int i = 1; i < n; ++i) {
            int of=f;
            f = max(max(f * nums[i], g * nums[i]), nums[i]);
            g = min(min(of * nums[i], g * nums[i]), nums[i]);
            res = max(res, f);
        }
        return res;
    }
};