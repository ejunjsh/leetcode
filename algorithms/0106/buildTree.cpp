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

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(postorder,0,postorder.size(),inorder,0,inorder.size());
    }

    TreeNode* helper(vector<int>& postorder,int i,int j,vector<int>& inorder,int ii,int jj)
    {

        if(i >= j || ii >= jj)
            return NULL;

        int mid = postorder[j-1];
        auto f = find(inorder.begin() + ii,inorder.begin() + jj,mid);

        int dis = f - inorder.begin() - ii;

        TreeNode* root = new TreeNode(mid);
        root -> left = helper(postorder,i,i + dis,inorder,ii,ii + dis);
        root -> right = helper(postorder,i + dis,j - 1 ,inorder,ii + dis + 1,jj);
        return root;
    }
};