class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int> q;
        multiset<pair<int, int>> s;
        for (int i = 0; i < Capital.size(); ++i) {
            s.insert({Capital[i], Profits[i]});
        }
        for (int i = 0; i < k; ++i) {
            for (auto it = s.begin(); it != s.end(); ++it) {
                if (it->first > W) break;
                q.push(it->second);
                s.erase(it);
            }
            if (q.empty()) break;
            W += q.top(); q.pop();
        }
        return W;
    }
};