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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        helper(paths,path,root,sum);
        return paths;
    }
    
    void helper(vector<vector<int>>& paths,vector<int> path, TreeNode* root,int sum){
        if(root==NULL){
            return;
        }
        sum -= root->val;
        if ((root->left == NULL) && (root->right == NULL))
        {
            if(sum==0){
                path.push_back(root->val);
                paths.push_back(path);
            }
            return;
        }
        else{
            path.push_back(root->val);
            helper(paths,path,root->left,sum);
            helper(paths,path,root->right,sum);
        }
    }
};