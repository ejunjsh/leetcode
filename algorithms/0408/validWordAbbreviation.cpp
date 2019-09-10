class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int m = word.size(), n = abbr.size(), p = 0, cnt = 0;
        for (int i = 0; i < abbr.size(); ++i) {
            if (abbr[i] >= '0' && abbr[i] <= '9') {
                if (cnt == 0 && abbr[i] == '0') return false;
                cnt = 10 * cnt + abbr[i] - '0';
            } else {
                p += cnt;
                if (p >= m || word[p++] != abbr[i]) return false;
                cnt = 0;
            }
        }
        return p + cnt == m;
    }
};