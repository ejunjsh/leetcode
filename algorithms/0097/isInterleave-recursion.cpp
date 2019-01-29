class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return is_Interleave(s1,0,s2,0,"",s3);
    }
    
    bool is_Interleave(string s1,int i,string s2,int j,string res,string s3)
    {
        if(res==s3 && i==s1.size() && j==s2.size())
            return true;
        bool ans=false;
        if(i<s1.size())
            ans|=is_Interleave(s1,i+1,s2,j,res+s1[i],s3);
        if(j<s2.size())
            ans|=is_Interleave(s1,i,s2,j+1,res+s2[j],s3);
        return ans;

    }
};