class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        queue<int> q{{kill}};
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < pid.size(); ++i) {
            m[ppid[i]].push_back(pid[i]);
        }
        while (!q.empty()) {
            int t = q.front(); q.pop();
            res.push_back(t);
            for (int p : m[t]) {
                q.push(p);
            }
        }
        return res;
    }
};