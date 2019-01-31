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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelMaker(res,root,0);
        return res;
    }
    
    void levelMaker(vector<vector<int>> &list, TreeNode *root, int level) {
            if(root == NULL) return;
            if(level >= list.size()) {
                list.insert(list.begin(),vector<int>());
            }
            levelMaker(list, root->left, level+1);
            levelMaker(list, root->right, level+1);
            list[list.size()-level-1].push_back(root->val);
        }
};