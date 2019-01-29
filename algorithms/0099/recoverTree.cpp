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
private:
    TreeNode* firstElement = NULL;
    TreeNode* secondElement = NULL;
    TreeNode* prevElement = NULL;

    
    void traverse(TreeNode* root) {
        
        if (root == NULL)
            return;
            
        traverse(root->left);
        
        if (firstElement == NULL && prevElement!=NULL && prevElement->val >= root->val) {
            firstElement = prevElement;
        }
    
        if (firstElement != NULL && prevElement->val >= root->val) {
            secondElement = root;
        }        
        prevElement = root;

        traverse(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
         // In order traversal to find the two elements
        traverse(root);
        
        // Swap the values of the two nodes
        int temp = firstElement->val;
        firstElement->val = secondElement->val;
        secondElement->val = temp;
    }

};