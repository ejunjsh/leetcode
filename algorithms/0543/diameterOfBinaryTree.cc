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
    int ans;
    
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;
    }
    
    int depth(TreeNode* node) {
        if (node == NULL) return 0;
        int L = depth(node->left);
        int R = depth(node->right);
        ans = max(ans, L+R);
        return max(L, R) + 1;
    }
};