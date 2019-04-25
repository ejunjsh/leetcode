class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        for (int i = 0, product = 1; i < n; product *= nums[i], i++)       //from left to right
            res[i] = product;
        for (int i = n - 1, product = 1; i >= 0; product *= nums[i], i--)  //from right to left
            res[i] *= product;
        return res;
    }
};