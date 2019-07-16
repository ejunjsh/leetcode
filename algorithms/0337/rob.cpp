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
    int rob(TreeNode* root) {
        if (root == NULL) return 0;
    
        int val = 0;

        if (root->left != NULL) {
            val += rob(root->left->left) + rob(root->left->right);
        }

        if (root->right != NULL) {
            val += rob(root->right->left) + rob(root->right->right);
        }

        return max(val + root->val, rob(root->left) + rob(root->right));
    }
};