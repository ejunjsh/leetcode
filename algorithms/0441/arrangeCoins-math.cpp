
// n = (x + 1) * x / 2
// x² + x = 2n
// x² + x + 1/4 - 1/4 = 2n
// (x + 1/2)² = 2n + 1 / 4
// (x + 1/2)² = (8n + 1) / 4
// x + 1/2 = sqrt(8n + 1) / 2
// x = (sqrt(8n + 1) / 2) - (1 / 2)
// x = (sqrt(8n + 1) - 1) / 2
class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((-1 + sqrt(1 + 8 * (long)n)) / 2);
    }
};