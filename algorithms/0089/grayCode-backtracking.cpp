class Solution {
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> result;
        backtracking(bits, result, n);
        return result;
    }

    void backtracking(bitset<32>& bits, vector<int>& result, int k){
        if (k==0) {
            result.push_back(bits.to_ulong());
        }
        else {
            backtracking(bits, result, k-1);
            bits.flip(k-1);
            backtracking(bits, result, k-1);
        }
    }
};