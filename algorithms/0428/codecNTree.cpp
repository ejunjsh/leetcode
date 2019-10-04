class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res;
        serializeHelper(root, res);
        return res;
    }
    
    void serializeHelper(Node* node, string& res) {
        if (!node) res += "#";
        else {
            res += to_string(node->val) + " " + to_string(node->children.size()) + " ";
            for (auto child : node->children) {
                serializeHelper(child, res);
            }
        }
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
    Node* deserializeHelper(istringstream& iss) {
        string val = "", size = "";
        iss >> val;
        if (val == "#") return NULL;
        iss >> size;
        Node *node = new Node(stoi(val), {});
        for (int i = 0; i < stoi(size); ++i) {
            node->children.push_back(deserializeHelper(iss));
        }
        return node;
    }
};