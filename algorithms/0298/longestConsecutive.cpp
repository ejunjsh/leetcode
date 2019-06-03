class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, 1, res);
        return res;
    }
    void dfs(TreeNode *root, int len, int &res) {
        res = max(res, len);
        if (root->left) {
            if (root->left->val == root->val + 1) dfs(root->left, len + 1, res);
            else dfs(root->left, 1, res);
        }
        if (root->right) {
            if (root->right->val == root->val + 1) dfs(root->right, len + 1, res);
            else dfs(root->right, 1, res);
        }
    }
};