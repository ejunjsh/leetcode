class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), beg = -1, end = -2, mn = nums[n-1], mx = nums[0];
        for (int i=1;i<n;i++) {
          mx = max(mx, nums[i]);
          mn = min(mn, nums[n-1-i]);
          if (nums[i] < mx) end = i;
          if (nums[n-1-i] > mn) beg = n-1-i; 
        }
        return end - beg + 1;
    }
};