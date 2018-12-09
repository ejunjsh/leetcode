class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        string res = "";
        for (int i = 0; i < strs[0].length(); i++){
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++){
                if (strs[j][i] != c){
                    return res;
                }
            }
            res += c;
        }
        return res;
        
    }
};