class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for (auto a : s) {
            b.flip(a);
        }
        return b.count() < 2;
    }
};