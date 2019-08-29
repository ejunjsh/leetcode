class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        int indexS = 0, indexT = 0;
        while (indexT < t.size()) {
            if (t[indexT] == s[indexS]) {
                indexS++;
                if (indexS == s.size()) return true;
            }
            indexT++;
        }
        return false;
    }
};