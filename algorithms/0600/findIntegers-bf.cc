class Solution {
public:
    int findIntegers(int n) {
        int count = 0;
        for (int i = 0; i <= n; i++)
            if (check(i))
                count++;
        return count;
    }
    
    bool check(int n){
        int i = 31;
        while (i > 0) {
            if ((n & (1 << i)) != 0 && (n & (1 << (i - 1))) != 0)
                return false;
            i--;
        }
        return true;
    }
};