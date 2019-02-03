class Solution{
public:
    int numDistinct(string s, string t){
        int m=t.size(),n=s.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
        return dp[m][n];
    }
};