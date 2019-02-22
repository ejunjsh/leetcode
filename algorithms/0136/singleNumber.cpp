// If we take XOR of zero and some bit, it will return that bit
// a XOR 0 = a
// If we take XOR of two same bits, it will return 0
// a XOR a = 0
// a XOR b XOR a = (a XOR a) XOR b = 0 XOR b  = b
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(auto n:nums){
            res^=n;
        }
        return res;
    }
};