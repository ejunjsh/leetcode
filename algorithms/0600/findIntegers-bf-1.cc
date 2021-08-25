class Solution {
public:
    int findIntegers(int n) {
        return find(0, 0, n, false);
    }
    
    int find(int i, int sum, int num, bool prev) {
        if (sum > num)
            return 0;
        if (1<<i > num)
            return 1;
        if (prev)
            return find(i + 1, sum, num, false);
        return find(i + 1, sum, num, false) + find(i + 1, sum + (1 << i), num, true);
    }
};