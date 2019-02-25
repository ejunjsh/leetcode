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
    vector<int> preorderTraversal(TreeNode* root) {
            vector<int> res ;
            vector<TreeNode*> stack;
            TreeNode* curr = root;
            while (curr != NULL || stack.size()) {
                while (curr != NULL) {
                    res.push_back(curr->val);
                    stack.push_back(curr);
                    curr = curr->left;
                }
                curr=stack.back();
                stack.pop_back();
                curr = curr->right;
            }
            return res;
     }
};