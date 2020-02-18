class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        dists[start[0]][start[1]] = 0;
        helper(maze, start[0], start[1], destination, dists);
        int res = dists[destination[0]][destination[1]];
        return (res == INT_MAX) ? -1 : res;
    }
    void helper(vector<vector<int>>& maze, int i, int j, vector<int>& destination, vector<vector<int>>& dists) {
        if (i == destination[0] && j == destination[1]) return;
        int m = maze.size(), n = maze[0].size();
        for (auto d : dirs) {
            int x = i, y = j, dist = dists[x][y];
            while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                x += d[0];
                y += d[1];
                ++dist;
            }
            x -= d[0];
            y -= d[1];
            --dist;
            if (dists[x][y] > dist) {
                dists[x][y] = dist;
                helper(maze, x, y, destination, dists);
            }
        }
    }
};