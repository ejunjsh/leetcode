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
    int sumNumbers(TreeNode* root) {
        return sum(root,0);
    }

    int sum(TreeNode* root, int s){
        if (root == NULL) 
            return 0;
        if (root->right == NULL && root->left == NULL) 
            return s*10 + root->val;
        return sum(root->left, s*10 + root->val) + sum(root->right, s*10 + root->val);
    }
};