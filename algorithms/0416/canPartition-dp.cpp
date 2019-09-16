class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if(sum % 2 != 0)
        {
            return false;
        }
        
        int target = sum / 2;
        
        int n = nums.size();
        
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
        //now we have to initialize the dp array
        
        for(int i = 1; i <= n; ++i)
        {
            dp[i][0] = true;
        }
        
        for(int j = 0; j <= target; ++j)
        {
            dp[0][j] = false;
        }
        
        dp[0][0] = true;
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j <= target; ++j)
            {
                if(j >= nums[i-1])
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - nums[i-1]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
            
            return dp[n][target];
    }
};