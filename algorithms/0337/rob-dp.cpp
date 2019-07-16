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
        unordered_map<TreeNode*,int> m;
        return robSub(root, m);
    }
    
private:
    int robSub(TreeNode* root, unordered_map<TreeNode*,int>& map) {
        if (root == NULL) return 0;
        if (map.find(root)!=map.end()) return map[root];

        int val = 0;

        if (root->left != NULL) {
            val += robSub(root->left->left, map) + robSub(root->left->right, map);
        }

        if (root->right != NULL) {
            val += robSub(root->right->left, map) + robSub(root->right->right, map);
        }

        val = max(val + root->val, robSub(root->left, map) + robSub(root->right, map));
        map[root]=val;

        return val;
    }
};