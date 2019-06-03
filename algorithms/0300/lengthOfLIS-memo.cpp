class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size()+1,vector<int>(nums.size(),-1));
        return lengthofLIS(nums, -1, 0, memo);
    }
    
private:
     int lengthofLIS(vector<int>& nums, int previndex, int curpos, vector<vector<int>>& memo) {
        if (curpos == nums.size()) {
            return 0;
        }
        if (memo[previndex + 1][curpos] >= 0) {
            return memo[previndex + 1][curpos];
        }
        int taken = 0;
        if (previndex < 0 || nums[curpos] > nums[previndex]) {
            taken = 1 + lengthofLIS(nums, curpos, curpos + 1, memo);
        }

        int nottaken = lengthofLIS(nums, previndex, curpos + 1, memo);
        memo[previndex + 1][curpos] = max(taken, nottaken);
        return memo[previndex + 1][curpos];
    }
};