class Solution {
public:
    int arrangeCoins(int n) {
        if (n <= 1) return n;
        long low = 1, high = n;
        while (low < high) {
            long mid = low + (high - low) / 2;
            if (mid * (mid + 1) / 2 <= n) low = mid + 1;
            else high = mid;
        }
        return low - 1;
    }
};