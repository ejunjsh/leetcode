class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<int, int> m;
            for (int j = 0; j < points.size(); ++j) {
                int a = points[i][0] - points[j][0];
                int b = points[i][1] - points[j][1];
                ++m[a * a + b * b];
            }
            for (auto it = m.begin(); it != m.end(); ++it) {
                res += it->second * (it->second - 1);
            }
        }
        return res;
    }
};