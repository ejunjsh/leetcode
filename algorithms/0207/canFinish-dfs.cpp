class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int> > graph(numCourses, vector<int>(0));
        vector<int> visit(numCourses, 0);
        for (auto a : prerequisites) {
            graph[a.second].push_back(a.first);
        }
        for (int i = 0; i < numCourses; ++i) {
            if (!dfs(graph, visit, i)) return false;
        }
        return true;
    }
    
    bool dfs(vector<vector<int> > &graph, vector<int> &visit, int i) {
        if (visit[i] == -1) return false;
        if (visit[i] == 1) return true;
        visit[i] = -1;
        for (auto a : graph[i]) {
            if (!dfs(graph, visit, a)) return false;
        }
        visit[i] = 1;
        return true;
    }
};