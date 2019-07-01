class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
        int res = 0;
        vector<vector<int> > g(n);
        vector<bool> v(n, false);
        for (auto a : edges) {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        for (int i = 0; i < n; ++i) {
            if (!v[i]) {
                ++res;
                dfs(g, v, i);
            }
        }
        return res;
    }
    void dfs(vector<vector<int> > &g, vector<bool> &v, int i) {
        if (v[i]) return;
        v[i] = true;
        for (int j = 0; j < g[i].size(); ++j) {
            dfs(g, v, g[i][j]);
        }
    }
};