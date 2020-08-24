class Solution {
public:
    int minDistance(string word1, string word2) {
        return word1.size() + word2.size() - 2 * lcs(word1, word2, word1.size(), word2.size());
    }
    
    int lcs(string word1, string word2, int m, int n) {
        if (m == 0 || n == 0)
            return 0;
        if (word1[m - 1] == word2[n - 1])
            return 1 + lcs(word1, word2, m - 1, n - 1);
        else
            return max(lcs(word1, word2, m, n - 1), lcs(word1, word2, m - 1, n));
    }
};