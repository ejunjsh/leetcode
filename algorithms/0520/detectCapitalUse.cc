class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (char c : word) if (isupper(c)) ++cnt;
        return !cnt || cnt == word.size() || cnt == 1 && isupper(word[0]);
    }
};