class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int islands = 0, neighbours = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    islands++; // count islands
                    if (i < grid.size() - 1 && grid[i + 1][j] == 1) neighbours++; // count down neighbours
                    if (j < grid[i].size() - 1 && grid[i][j + 1] == 1) neighbours++; // count right neighbours
                }
            }
        }

        return islands * 4 - neighbours * 2;
    }
};