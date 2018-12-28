class Solution {
public:
    bool isMatch(string s, string p) {
        const char* s1=s.data();
        const char* p1=p.data();
        const char* star=NULL;
        const char* ss=s1;
        
         while (*s1){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length 
            if ((*p1=='?')||(*p1==*s1)){s1++;p1++;continue;} 

            // * found in pattern, track index of *, only advancing pattern pointer 
            if (*p1=='*'){star=p1++; ss=s1;continue;} 

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p1 = star+1; s1=++ss;continue;} 

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            return false;
        }

       //check for remaining characters in pattern
        while (*p1=='*'){p1++;}

        return !*p1;  
    }
};
