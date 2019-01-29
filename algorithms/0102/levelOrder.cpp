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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode*> s;
        vector<int> level;
        queue<TreeNode*> nodes;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* n = s.front();
            s.pop();
            level.push_back(n->val);
            if(n->left)
                nodes.push(n->left);
            if(n->right)
                nodes.push(n->right);

            if(s.empty())
            {
                s.swap(nodes);
                result.push_back(level);
                level.clear();
            }
        }

        return result;
    }
};