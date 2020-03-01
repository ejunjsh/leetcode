class Solution {
public:
    int longestPalindromeSubseq(string s) {
        return longestPalindromeSubseq(0,s.size()-1,s); 
    }
    
    int longestPalindromeSubseq(int l, int r, string &s) {
        if(l==r) return 1;
        if(l>r) return 0; 
        return s[l]==s[r] ? 2 + longestPalindromeSubseq(l+1,r-1, s) : 
            max(longestPalindromeSubseq(l+1,r, s),longestPalindromeSubseq(l,r-1, s)); 
    }
};