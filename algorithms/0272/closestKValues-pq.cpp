class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        priority_queue<pair<double, int>> q;
        inorder(root, target, k, q);
        while (!q.empty()) {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
    void inorder(TreeNode *root, double target, int k, priority_queue<pair<double, int>> &q) {
        if (!root) return;
        inorder(root->left, target, k, q);
        q.push({abs(root->val - target), root->val});
        if (q.size() > k) q.pop();
        inorder(root->right, target, k, q);
    }
};