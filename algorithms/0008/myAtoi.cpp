class Solution {
public:
    int myAtoi(string str) {
        int i, ans, sign, backup;
        i=0;
        while(i<str.length() && str.at(i) == ' ')
            i++;
        sign = 1; // positive
        if(i<str.length() && str.at(i) == '+')
        {
            i++;
        }
        else if(i<str.length() && str.at(i) == '-')
        {
            sign = -1; // negative
            i++;
        }
        ans=0;
        while(i<str.length() && isdigit(str.at(i)))
        {
            backup = ans;
            ans = ans*10+(str.at(i)-'0');
            if(ans<0 || backup != (ans-(str.at(i)-'0'))/10)
                return sign==1?INT_MAX:INT_MIN;
            i++;
        }
        return ans*sign;
    }
};