class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int idx = -1, res = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1 || words[i] == word2) {
                if (idx != -1 && words[idx] != words[i]) {
                    res = min(res, i - idx);
                }
                idx = i;
            }
        }
        return res;
    }
};