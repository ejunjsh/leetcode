class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = flights.size(), k = days[0].size();
        vector<int> dp(n, INT_MIN);
        dp[0] = 0;
        for (int j = 0; j < k; ++j) {
            vector<int> t(n, INT_MIN);
            for (int i = 0; i < n; ++i) {
                for (int p = 0; p < n; ++p) {
                    if (i == p || flights[p][i]) {
                        t[i] = max(t[i], dp[p] + days[i][j]);
                    }
                }
            }
            dp = t;
        }
        return *max_element(dp.begin(), dp.end());
    }
};