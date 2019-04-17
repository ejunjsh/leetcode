class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> h, res;
        multiset<int> m;
        int pre = 0, cur = 0;
        for (auto &a : buildings) {
            h.push_back({a[0], -a[2]});
            h.push_back({a[1], a[2]});
        }
        sort(h.begin(), h.end());
        m.insert(0);
        for (auto &a : h) {
            if (a.second < 0) m.insert(-a.second);
            else m.erase(m.find(a.second));
            cur = *m.rbegin();
            if (cur != pre) {
                res.push_back({a.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};