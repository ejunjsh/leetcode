class Solution {
public:
    int countComponents(int n, vector<pair<int, int> >& edges) {
        int res = n;
        vector<int> root(n);
        for (int i = 0; i < n; ++i) root[i] = i;
        for (auto a : edges) {
            int x = find(root, a.first), y = find(root, a.second);
            if (x != y) {
                --res;
                root[y] = x;
            }
        }
        return res;
    }
    int find(vector<int> &root, int i) {
        while (root[i] != i) i = root[i];
        return i;
    }
};