class Solution {
public:
    bool isMatch(string text, string pattern) {
        bool dp[text.size()+1][pattern.size()+1] ;
        
        
        for(int i= 0;i<=text.size();i++){
            for(int j= 0;j<=pattern.size();j++){
                dp[i][j]=false;
            }
        }
        
        dp[text.size()][pattern.size()] = true;

        for (int i = text.size(); i >= 0; i--){
            for (int j = pattern.size() - 1; j >= 0; j--){
                bool first_match = (i < text.size() &&
                                       (pattern[j] == text[i] ||
                                        pattern[j] == '.'));
                if (j + 1 < pattern.size() && pattern[j+1] == '*'){
                    dp[i][j] = dp[i][j+2] || first_match && dp[i+1][j];
                } else {
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};