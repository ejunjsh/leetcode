class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> prime(n, true);
        for (int i = 2; i < n; ++i) {
            if (prime[i]) {
                ++res;
                for (int j = 2; i * j < n; ++j) {
                    prime[i * j] = false;
                }
            }
        }
        return res;
    }
};