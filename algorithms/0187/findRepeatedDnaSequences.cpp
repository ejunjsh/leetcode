class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<int,int> st;
        unordered_map<int, int> m{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int cur = 0;
        for (int i = 0; i < 9; ++i) cur = cur << 2 | m[s[i]];
        for (int i = 9; i < s.size(); ++i) {
            cur = ((cur & 0x3ffff) << 2) | (m[s[i]]);
            if (st.count(cur)) {
                if (st[cur] == 1) res.push_back(s.substr(i - 9, 10));
                ++st[cur]; 
            } else {
                st[cur] = 1;
            }
        }
        return res;
    }
};