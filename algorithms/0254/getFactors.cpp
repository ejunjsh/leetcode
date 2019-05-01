class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                vector<vector<int>> v = getFactors(n / i);
                vector<int> out{i, n / i};
                res.push_back(out);
                for (auto a : v) {
                    if (i <= a[0]) {
                        a.insert(a.begin(), i);
                        res.push_back(a);
                    }
                }
            }
        }
        return res;
    }
};