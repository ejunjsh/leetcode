/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        travel(root, res);
        return res;
    }
    void travel(Node* node, vector<int>& res) {
        if (!node) return;
        for (Node* child : node->children) {
            travel(child, res);
        }
        res.push_back(node->val);
    }
};