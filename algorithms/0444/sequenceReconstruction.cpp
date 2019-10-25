class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        if (seqs.empty()) return false;
        int n = org.size(), cnt = n - 1;
        vector<int> pos(n + 1, 0), flags(n + 1, 0);
        bool existed = false;
        for (int i = 0; i < n; ++i) pos[org[i]] = i;
        for (auto& seq : seqs) {
            for (int i = 0; i < seq.size(); ++i) {
                existed = true;
                if (seq[i] <= 0 || seq[i] > n) return false;
                if (i == 0) continue;
                int pre = seq[i - 1], cur = seq[i];
                if (pos[pre] >= pos[cur]) return false;
                if (flags[cur] == 0 && pos[pre] + 1 == pos[cur]) {
                    flags[cur] = 1; --cnt;
                }
            }
        }
        return cnt == 0 && existed;
    }
};
