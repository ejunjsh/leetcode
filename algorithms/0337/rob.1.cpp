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
        vector<int> res = robSub(root);
        return max(res[0], res[1]);
    }
    
private:
    vector<int> robSub(TreeNode* root) {
        if (root == NULL) return {0,0};
    
        vector<int> left = robSub(root->left);
        vector<int> right = robSub(root->right);
        vector<int> res = {0,0};

        res[0] = max(left[0], left[1]) + max(right[0], right[1]);
        res[1] = root->val + left[0] + right[0];

        return res;
    }
};