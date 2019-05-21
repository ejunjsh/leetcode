class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> g(26, vector<bool>(26, false));
        vector<bool> visited(26, false);
        string res = "";
        for (string word : words) {
            for (char c : word) {
                g[c - 'a'][c - 'a'] = true;
            }
        }
        for (int i = 0; i < (int)words.size() - 1; ++i) {
            int mn = min(words[i].size(), words[i + 1].size()), j = 0;
            for (; j < mn; ++j) {
                if (words[i][j] != words[i + 1][j]) {
                    g[words[i][j] - 'a'][words[i + 1][j] - 'a'] = true;
                    break;
                }
            }
            if (j == mn && words[i].size() > words[i + 1].size()) return "";
        }
        for (int i = 0; i < 26; ++i) {
            if (!dfs(g, i, visited, res)) return "";
        }
        return string(res.rbegin(), res.rend());
    }
    bool dfs(vector<vector<bool>>& g, int idx, vector<bool>& visited, string& res) {
        if (!g[idx][idx]) return true;
        visited[idx] = true;
        for (int i = 0; i < 26; ++i) {
            if (i == idx || !g[idx][i]) continue;
            if (visited[i]) return false;
            if (!dfs(g, i, visited, res)) return false;
        }
        visited[idx] = false;
        g[idx][idx] = false;
        res += 'a' + idx;
        return true;
    }
};