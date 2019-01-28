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
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
          return true;

        return isBSTHelper(root, NULL, NULL);
    }
    
    bool isBSTHelper(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (minNode!=NULL&&node->val <= minNode->val)
          return false;
        if (maxNode!=NULL&&maxNode->val <= node->val)
          return false;

        bool left = node->left != NULL ? isBSTHelper(node->left, minNode, node) : true;
        if (left) {
          bool right = node->right != NULL ? isBSTHelper(node->right, node, maxNode) : true;
          return right;
        } else
          return false;
  }
};