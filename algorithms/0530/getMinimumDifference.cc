/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    int getMinimumDifference(TreeNode* root) {
        auto res = INT_MAX, val = -1;
        inorderTraverse(root, val, res);
        return res;
    }
    
    void inorderTraverse(TreeNode* root, int& val, int& res) {
        if (root->left != NULL) inorderTraverse(root->left, val, res);
        if (val >= 0) res = min(res, root->val - val);
        val = root->val;
        if (root->right != NULL) inorderTraverse(root->right, val, res);
    }
};