class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        vector<vector<int>> dists(m, vector<int>(n, INT_MAX));
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        auto cmp = [](vector<int>& a, vector<int>& b) {
            return a[2] > b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp) > pq(cmp);
        pq.push({start[0], start[1], 0});
        dists[start[0]][start[1]] = 0;
        while (!pq.empty()) {
            auto t = pq.top(); pq.pop();for (auto dir : dirs) {
                int x = t[0], y = t[1], dist = dists[t[0]][t[1]];
                while (x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 0) {
                    x += dir[0];
                    y += dir[1];
                    ++dist;
                }
                x -= dir[0];
                y -= dir[1];
                --dist;
                if (dists[x][y] > dist) {
                    dists[x][y] = dist;
                    if (x != destination[0] || y != destination[1]) pq.push({x, y, dist});
                }
            }
        }
        int res = dists[destination[0]][destination[1]];
        return (res == INT_MAX) ? -1 : res;
    }
};