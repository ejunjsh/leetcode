class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) mp[nums[i]] = i;
        
        vector<string> ans(mp.size(), "");
        int cnt = 1; 
        for (map<int, int>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++, cnt++) {
            if (cnt == 1) ans[it->second] = "Gold Medal";
            else if (cnt == 2) ans[it->second] = "Silver Medal";
            else if (cnt == 3) ans[it->second] = "Bronze Medal";
            else ans[it->second] = to_string(cnt);
        }
        
        return ans;
    }
};