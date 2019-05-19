class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_set<string> res;
        unordered_map<char, int> m;
        string t = "", mid = "";
        for (auto a : s) ++m[a];
        for (auto it : m) {
            if (it.second % 2 == 1) mid += it.first;
            t += string(it.second / 2, it.first);
            if (mid.size() > 1) return {};
        }
        permute(t, 0, mid, res);
        return vector<string>(res.begin(), res.end());
    }
    void permute(string &t, int start, string mid, unordered_set<string> &res) {
        if (start >= t.size()) {
            res.insert(t + mid + string(t.rbegin(), t.rend()));
        } 
        for (int i = start; i < t.size(); ++i) {
            if (i != start && t[i] == t[start]) continue;
            swap(t[i], t[start]);
            permute(t, start + 1, mid, res);
            swap(t[i], t[start]);
        }
    }
};