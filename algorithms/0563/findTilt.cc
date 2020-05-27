/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int tilt=0;
    
    int findTilt(TreeNode* root) {
        traverse(root);
        return tilt;
    }
    
    int traverse(TreeNode* root){
        if (root == NULL )
            return 0;
        int left = traverse(root->left);
        int right = traverse(root->right);
        tilt += abs(left-right);
        return left + right + root->val;
    }
};