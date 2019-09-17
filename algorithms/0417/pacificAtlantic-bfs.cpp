class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        vector<vector<int>> res;
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> q1, q2;
        vector<vector<bool>> pacific(m, vector<bool>(n, false)), atlantic = pacific;
        for (int i = 0; i < m; ++i) {
            q1.push({i, 0}); 
            q2.push({i, n - 1});
            pacific[i][0] = true;
            atlantic[i][n - 1] = true;
        }
        for (int i = 0; i < n; ++i) {
            q1.push({0, i});
            q2.push({m - 1, i});
            pacific[0][i] = true;
            atlantic[m - 1][i] = true;
        }
        bfs(matrix, pacific, q1);
        bfs(matrix, atlantic, q2);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void bfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        while (!q.empty()) {
            auto t = q.front(); q.pop();
            for (auto dir : dirs) {
                int x = t.first + dir[0], y = t.second + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || matrix[x][y] < matrix[t.first][t.second]) continue;
                visited[x][y] = true;
                q.push({x, y});
            }
        }
    }
};