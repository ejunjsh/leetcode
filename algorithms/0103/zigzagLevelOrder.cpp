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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if(!root)
            return result;

        stack<TreeNode*> s;
        vector<int> level;
        stack<TreeNode*> nodes;
        s.push(root);
        bool leftToRight=true;
        while(!s.empty())
        {
            TreeNode* n = s.top();
            s.pop();
            level.push_back(n->val);
            if(leftToRight){
                if(n->left)
                    nodes.push(n->left);
                if(n->right)
                    nodes.push(n->right);
            }else{
                if(n->right)
                    nodes.push(n->right);
                if(n->left)
                    nodes.push(n->left);
            }
            if(s.empty())
            {
                s.swap(nodes);
                result.push_back(level);
                level.clear();
                leftToRight=!leftToRight;
            }
        }

        return result;
    }
};