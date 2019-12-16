class Solution {
public:
    int findComplement(int num) {
        unsigned mask = ~0;
        while (num & mask) mask <<= 1;
        return ~mask & ~num;
    }
};
// example:
// num          = 00000101
// mask         = 11111000
// ~mask & ~num = 00000010