class Solution {
public:
    int longestPalindrome(string s) {
        int count[128]={0};
        for (char c: s)
            count[c]++;

        int ans = 0;
        for (int v: count) {
            ans += v / 2 * 2;
            if (ans % 2 == 0 && v % 2 == 1)
                ans++;
        }
        return ans;
    }
};