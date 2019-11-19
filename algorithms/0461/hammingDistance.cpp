class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, n = x ^ y;
        while (n) {
            ++res;
            n &= n - 1;
        }
        return res;
    }
};