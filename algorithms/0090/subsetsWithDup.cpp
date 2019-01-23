class Solution{
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums){
            sort(nums.begin(),nums.end());
            vector<vector<int>> subs;
            vector<int> sub;
            subsetsWithDup(nums, 0, sub, subs);
            return subs;
        }
    private:
        void subsetsWithDup(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs) {
            subs.push_back(sub);
            for (int i = start; i < nums.size(); i++) {
                if (i == start || nums[i] != nums[i - 1]) { 
                    sub.push_back(nums[i]);
                    subsetsWithDup(nums, i + 1, sub, subs);
                    sub.pop_back();
                }
            }
        }
};
