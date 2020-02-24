class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) return nullptr;
        if (node->right) {
            node = node->right;
            while (node && node->left) node = node->left;
            return node;
        }
        while (node) {
            if (!node->parent) return nullptr;
            if (node == node->parent->left) return node->parent;
            node = node->parent;
        }
        return node;
    }
};