class Solution {
public:
    TreeNode* str2tree(string s) {
        if (s.empty()) return NULL;
        auto found = s.find('(');
        int val = (found == string::npos) ? stoi(s) : stoi(s.substr(0, found));
        TreeNode *cur = new TreeNode(val);
        if (found == string::npos) return cur;
        int start = found, cnt = 0;
        for (int i = start; i < s.size(); ++i) {
            if (s[i] == '(') ++cnt;
            else if (s[i] == ')') --cnt;
            if (cnt == 0 && start == found) {
                cur->left = str2tree(s.substr(start + 1, i - start - 1));
                start = i + 1;
            } else if (cnt == 0) {
                cur->right = str2tree(s.substr(start + 1, i - start - 1));
            }
        }
        return cur;
    }
};