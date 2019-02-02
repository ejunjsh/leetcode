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
private:
    TreeNode* prev = NULL;

public:
    void flatten(TreeNode* root) {
        if (root == NULL)
        return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};