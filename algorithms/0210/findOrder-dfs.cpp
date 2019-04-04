class Solution {
private:
    static const int WHITE=1;
    static const int GRAY=2;
    static const int BLACK=3;

    bool isPossible;
    unordered_map<int,int> color;
    unordered_map<int,vector<int>> adjList;
    vector<int> topologicalOrder;

    void init(int numCourses,vector<pair<int, int>>& prerequisites) {
      isPossible = true;

      // By default all vertces are WHITE
      for (int i = 0; i < numCourses; i++) {
        color[i]=WHITE;
      }

      // Create the adjacency list representation of the graph
      for (int i = 0; i < prerequisites.size(); i++) {
        int dest = prerequisites[i].first;
        int src = prerequisites[i].second;
        auto lst = adjList[src];
        lst.push_back(dest);
        adjList[src]=lst;
      }
    };

    void dfs(int node) {

      // Don't recurse further if we found a cycle already
      if (!isPossible) {
        return;
      }

      // Start the recursion
      color[node]=GRAY;

      // Traverse on neighboring vertices
      for (int neighbor : adjList[node]) {
        if (color[neighbor] == WHITE) {
          dfs(neighbor);
        } else if (color[neighbor] == GRAY) {
          // An edge to a GRAY vertex represents a cycle
          isPossible = false;
        }
      }

      // Recursion ends. We mark it as black
      color[node]=BLACK;
      topologicalOrder.push_back(node);
    };

public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        init(numCourses,prerequisites);

        // If the node is unprocessed, then call dfs on it.
        for (int i = 0; i < numCourses; i++) {
          if (color[i] == WHITE) {
            dfs(i);
          }
        }

        vector<int> order;
        if (isPossible) {
          for (int i = 0; i < numCourses; i++) {
            auto l= topologicalOrder.back();
            topologicalOrder.pop_back();
            order.push_back(l);
          }
        }

        return order;
    }
};

