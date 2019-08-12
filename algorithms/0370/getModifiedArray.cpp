class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length + 1);
        for (auto a : updates) {
            res[a[0]] += a[2];
            res[a[1] + 1] -= a[2];
        }
        for (int i = 1; i < res.size(); ++i) {
            res[i] += res[i - 1];
        }
        res.pop_back();
        return res;
    }
}