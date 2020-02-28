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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL) {
            return res;
        }
        
        helper(root, 0, res);
        
        return res;
    }
    
    void helper(TreeNode* node, int level,vector<int>& res) {
        if (node == NULL) {
            return;
        }
        
        if (res.size() < level + 1) {
            res.push_back(node->val);
        } else {
            if (res[level] < node->val) {
                res[level] = node->val;
            }
        }
        helper(node->left, level+1,res);
        helper(node->right, level+1,res);
    }
};