class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;
        int min1 = 0, min2 = 0, idx1 = -1;
        for (int i = 0; i < costs.size(); ++i) {
            int m1 = INT_MAX, m2 = m1, id1 = -1;
            for (int j = 0; j < costs[i].size(); ++j) {
                int cost = costs[i][j] + (j == idx1 ? min2 : min1);
                if (cost < m1) {
                    m2 = m1; m1 = cost; id1 = j;
                } else if (cost < m2) {
                    m2 = cost;
                }
            }
            min1 = m1; min2 = m2; idx1 = id1;
        }
        return min1;
    }
};