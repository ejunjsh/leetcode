class Solution{
    public:
        vector<vector<int>> subsets(vector<int>& nums){
            vector<vector<int>> subs;
            vector<int> sub;
            subsets(nums, 0, sub, subs);
            return subs;
        }
    private:
        void subsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
            subs.push_back(sub);
            for (int i = start; i < nums.size(); i++) {
                sub.push_back(nums[i]);
                subsets(nums, i + 1, sub, subs);
                sub.pop_back();
            }
        }
};
