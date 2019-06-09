class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited{{s}};
        queue<string> q{{s}},tmp;
        bool found = false;
        while (!q.empty()) {
            string t = q.front(); q.pop();
            if (isValid(t)) {
                res.push_back(t);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < t.size(); ++i) {
                if (t[i] != '(' && t[i] != ')') continue;
                string str = t.substr(0, i) + t.substr(i + 1);
                if (!visited.count(str)) {
                    tmp.push(str);
                    visited.insert(str);
                }
            }
            if(q.empty()&&!found) swap(q,tmp);
        }
        return res;
    }
    bool isValid(string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '(') ++cnt;
            else if (t[i] == ')' && --cnt < 0) return false;
        }
        return cnt == 0;
    }
};