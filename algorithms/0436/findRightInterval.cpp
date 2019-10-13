class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> hash;
        vector<int> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
            hash[intervals[i][0]] = i;
        for (auto in : intervals) {
            auto itr = hash.lower_bound(in[1]);
            if (itr == hash.end()) res.push_back(-1);
            else res.push_back(itr->second);
        }
        return res;
    }
};