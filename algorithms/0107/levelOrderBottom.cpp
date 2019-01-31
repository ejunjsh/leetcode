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
        vector<vector<int>>  retval;
        leverorder(root,retval,0);
        reverse(retval.begin(),retval.end());
        return retval;
    }
    
    void leverorder(TreeNode* root,vector<vector<int>> &v, int cruentlevel){
        if(root==NULL) return;
        if(v.empty()||cruentlevel>(v.size()-1)){
            v.push_back(vector<int>());
        }
        v[cruentlevel].push_back(root->val);
        leverorder(root->left,v,cruentlevel+1);
        leverorder(root->right,v,cruentlevel+1);
    }
};