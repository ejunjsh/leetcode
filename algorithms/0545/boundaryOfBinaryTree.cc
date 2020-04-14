class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (!root) return {};
        vector<int> res;
        if (root->left || root->right) res.push_back(root->val);
        leftBoundary(root->left, res);
        leaves(root, res);
        rightBoundary(root->right, res);
        return res;
    }
    void leftBoundary(TreeNode* node, vector<int>& res) {
        if (!node || (!node->left && !node->right)) return;
        res.push_back(node->val);
        if (!node->left) leftBoundary(node->right, res);
        else leftBoundary(node->left, res);
    }
    void rightBoundary(TreeNode* node, vector<int>& res) {
        if (!node || (!node->left && !node->right)) return;
        if (!node->right) rightBoundary(node->left, res);
        else rightBoundary(node->right, res);
        res.push_back(node->val);
    }
    void leaves(TreeNode* node, vector<int>& res) {
        if (!node) return;
        if (!node->left && !node->right) {
            res.push_back(node->val);
        }
        leaves(node->left, res);
        leaves(node->right, res);
    }
};