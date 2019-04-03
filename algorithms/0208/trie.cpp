class TrieNode {

public:
    bool containsKey(char ch) {
        return links[ch -'a'] != NULL;
    }
    TrieNode* get(char ch) {
        return links[ch -'a'];
    }
    void put(char ch, TrieNode* node) {
        links[ch -'a'] = node;
    }
    bool isEnd=false;

private:
    TrieNode* links[26]={0};
};

class Trie {
private:
    TrieNode* root;

    // search a prefix or whole key in trie and
    // returns the node where search ends
    TrieNode* searchPrefix(string word) {
        TrieNode* node = root;
        for (char c:word) {
           if (node->containsKey(c)) {
               node = node->get(c);
           } else {
               return NULL;
           }
        }
        return node;
    };

public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* node = root;
        for (char c:word) {
            if (!node->containsKey(c)) {
                node->put(c, new TrieNode());
            }
            node = node->get(c);
        }
        node->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* node = searchPrefix(word);
        return node != NULL && node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* node = searchPrefix(prefix);
        return node != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

