class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        int res = INT_MAX;
        unordered_map<int, int> m;
        for (auto t : transactions) {
            m[t[0]] -= t[2];
            m[t[1]] += t[2];
        }
        vector<int> accnt;
        for (auto a : m) {
            if (a.second != 0) accnt.push_back(a.second);
        }
        helper(accnt, 0, 0, res);
        return res;
    }
    void helper(vector<int>& accnt, int start, int cnt, int& res) {
        int n = accnt.size();
        while (start < n && accnt[start] == 0) ++start;
        if (start == n) {
            res = min(res, cnt);
            return;
        }
        for (int i = start + 1; i < n; ++i) {
            if ((accnt[i] < 0 && accnt[start] > 0) || (accnt[i] > 0 && accnt[start] < 0)) {
                accnt[i] += accnt[start];
                helper(accnt, start + 1, cnt + 1, res);
                accnt[i] -= accnt[start];
            }
        }
    }
};