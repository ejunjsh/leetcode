class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s; // set is ordered automatically 
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) s.erase(nums[i-k-1]); 
            auto pos = s.lower_bound((long)nums[i] - t); 
            if (pos != s.end() && *pos - nums[i] <= t) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};