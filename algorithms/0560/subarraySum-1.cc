class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        vector<int> sum(nums.size()+1);
        sum[0] = 0;
        for (int i = 1; i <= nums.size(); i++)
            sum[i] = sum[i - 1] + nums[i - 1];
        for (int start = 0; start < nums.size(); start++) {
            for (int end = start + 1; end <= nums.size(); end++) {
                if (sum[end] - sum[start] == k)
                    count++;
            }
        }
        return count;
    }
};