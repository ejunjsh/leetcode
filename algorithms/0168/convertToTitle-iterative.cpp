class Solution {
public:
    string convertToTitle(int n) {
        string res="";
        while(n){
            res+=(char) ((n - 1) % 26 + 'A');
            n=(n - 1) / 26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};