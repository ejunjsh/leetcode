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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         // Value of p
        int pVal = p->val;

        // Value of q;
        int qVal = q->val;

        // Start from the root node of the tree
        TreeNode* node = root;

        // Traverse the tree
        while (node != NULL) {

            // Value of ancestor/parent node.
            int parentVal = node->val;

            if (pVal > parentVal && qVal > parentVal) {
                // If both p and q are greater than parent
                node = node->right;
            } else if (pVal < parentVal && qVal < parentVal) {
                // If both p and q are lesser than parent
                node = node->left;
            } else {
                // We have found the split point, i.e. the LCA node.
                return node;
            }
        }
        return NULL;
    }
};