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
    int countNodes(TreeNode* root) {
        dfs(root);
        return count;
    }
    
private:
    int count;
    void dfs(TreeNode* root){
        if(root==NULL){
            return;
        }
        count++;
        dfs(root->left);
        dfs(root->right);
    }
};