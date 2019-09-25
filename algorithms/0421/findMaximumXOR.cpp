struct TrieNode{
    int val;
    TrieNode *left;
    TrieNode *right;
    TrieNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode(0);

        //build tree
        TrieNode* curNode = root;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 31; j >= 0; j--) {
                int tmp = nums[i] & (1 << j);
                if(tmp == 0){
                    if(!curNode->right){
                        curNode->right = new TrieNode(0);
                    }
                    curNode = curNode->right;
                }else{
                    if(!curNode->left){
                        curNode->left = new TrieNode(1);
                    }
                    curNode = curNode->left;
                }
            }
            curNode = root;
        }

        //find the max
        int max = 0;
        for(int i = 0; i < nums.size(); i++){
            int res = 0;
            for(int j = 31; j >= 0; j--){
                int tmp = nums[i] & (1 << j);
                if(curNode->left && curNode->right){
                    if(tmp == 0){
                        curNode = curNode->left;
                    }else {
                        curNode = curNode->right;
                    }    
                }else {
                    curNode = curNode->left == NULL ? curNode->right:curNode->left;
                }
                res += tmp ^ (curNode->val << j);
            }
            curNode = root;
            max = max > res?max:res;
        }

        return max;
    }
};