// D D I I D I
// 1 2 3 4 5 6 7
// 3 2 1 4 6 5 7
class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res;
        for (int i = 0; i < s.size() + 1; ++i) {
            if (i == s.size() || s[i] == 'I') {
                int size = res.size();
                for (int j = i + 1; j > size; --j) {
                    res.push_back(j);
                }
            }
        }
        return res;
    }
};