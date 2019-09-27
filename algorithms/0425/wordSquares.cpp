class Solution {
public:
    struct TrieNode {
        vector<int> indexs;
        vector<TrieNode*> children;
        TrieNode(): children(26, nullptr) {}
    };
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode *root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
            TrieNode *t = root;
            for (int j = 0; j < words[i].size(); ++j) {
                if (!t->children[words[i][j] - 'a']) {
                    t->children[words[i][j] - 'a'] = new TrieNode();
                }
                t = t->children[words[i][j] - 'a'];
                t->indexs.push_back(i);
            }
        }
        return root;
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        TrieNode *root = buildTrie(words);
        vector<string> out(words[0].size());
        vector<vector<string>> res;
        for (string word : words) {
            out[0] = word;
            helper(words, 1, root, out, res);
        }
        return res;
    }
    void helper(vector<string>& words, int level, TrieNode* root, vector<string>& out, vector<vector<string>>& res) {
        if (level >= words[0].size()) {
            res.push_back(out);
            return;
        }
        string str = "";
        for (int i = 0; i < level; ++i) {
            str += out[i][level];
        }
        TrieNode *t = root;
        for (int i = 0; i < str.size(); ++i) {
            if (!t->children[str[i] - 'a']) return;
            t = t->children[str[i] - 'a'];
        }
        for (int idx : t->indexs) {
            out[level] = words[idx];
            helper(words, level + 1, root, out, res);
        }
    }
};