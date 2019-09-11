class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long left = 0, right = 0;
        for (int i = 0; i < nums.size(); ++i) {
            left = max((int)left, nums[i]);
            right += nums[i];
        }
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (can_split(nums, m, mid)) right = mid;
            else left = mid + 1;
        }
        return right;
    }
private:
    bool can_split(vector<int>& nums, int m, int sum) {
        long cnt = 1, curSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            curSum += nums[i];
            if (curSum > sum) {
                curSum = nums[i];
                ++cnt;
                if (cnt > m) return false;
            }
        }
        return true;
    }
};