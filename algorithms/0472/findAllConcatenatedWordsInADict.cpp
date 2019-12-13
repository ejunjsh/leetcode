class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        sort(words.begin(), words.end(), [](const string &a, const string &b){
            return a.length()<b.length();
        });

        unordered_set<string> st;
        vector<string> res;
        
        for(int i=0;i<words.size();i++)
        {
            if(canForm(words[i], st))
            {
                res.push_back(words[i]);
            }
            st.insert(words[i]);
        }
        
        return res;
    }
    
    
   bool canForm(string s, unordered_set<string> &dict) {
         if(dict.size()==0) 
            return false;
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};