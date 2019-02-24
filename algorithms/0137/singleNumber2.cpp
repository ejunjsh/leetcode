class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0,b=0;
        for(auto n:nums){
            b=b^n&~a;
            a=a^n&~b;
        }
        return a|b;
    }
};