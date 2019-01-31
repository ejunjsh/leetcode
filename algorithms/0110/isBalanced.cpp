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
    bool result = true;

    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return result;
    }

    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if (abs(l - r) > 1)
            result = false;
        return 1 + max(l, r);
    }
};