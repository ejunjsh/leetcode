class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> count(26, 0);
        int len = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (i > 0 && (p[i] == p[i - 1] + 1 || p[i - 1] - p[i] == 25)) {
                ++len;
            } else {
                len = 1;
            }
            count[p[i] - 'a'] = max(count[p[i] - 'a'], len);
        }
        
        int sum=0;
        
        for (int i = 0; i < 26; i++) {
            sum += count[i];
        }
        return sum;
    }
};