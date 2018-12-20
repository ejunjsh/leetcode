class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size();
        
        if(nums[lo]>target) return lo;
        if(nums[hi-1]<target) return hi;

        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] >= target) {
                hi = mid;
            }
            else {
                lo = mid+1;
            }
        }

        return lo;
    }
};