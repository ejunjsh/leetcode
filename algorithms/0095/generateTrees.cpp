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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
          return  vector<TreeNode*>();
        }
        return generate_trees(1, n);
    }
    vector<TreeNode*> generate_trees(int start, int end) {
        vector<TreeNode*> all_trees;
        if (start > end) {
          all_trees.push_back(NULL);
          return all_trees;
        }

        // pick up a root
        for (int i = start; i <= end; i++) {
          // all possible left subtrees if i is choosen to be a root
          vector<TreeNode*> left_trees = generate_trees(start, i - 1);

          // all possible right subtrees if i is choosen to be a root
          vector<TreeNode*> right_trees = generate_trees(i + 1, end);

          // connect left and right trees to the root i
          for (TreeNode* l : left_trees) {
            for (TreeNode* r : right_trees) {
              TreeNode* current_tree = new TreeNode(i);
              current_tree->left = l;
              current_tree->right = r;
              all_trees.push_back(current_tree);
            }
          }
        }
        return all_trees;
  }
};