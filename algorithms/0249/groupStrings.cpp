class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        unordered_map<string, multiset<string>> m;
        for (auto a : strings) {
            string t = "";
            for (char c : a) {
                t += to_string((c + 26 - a[0]) % 26) + ",";
            }
            m[t].insert(a);
        }
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(vector<string>(it->second.begin(), it->second.end()));
        }
        return res;
    }
};