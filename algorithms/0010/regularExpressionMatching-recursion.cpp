class Solution {
public:
    bool isMatch(string text, string pattern) {
        if (pattern=="") return text=="";
        bool first_match = (text!="" &&
                               (pattern[0] == text[0] || pattern[0] == '.'));

        if (pattern.size() >= 2 && pattern[1] == '*'){
            return (isMatch(text, pattern.substr(2,pattern.size()-2)) ||
                    (first_match && isMatch(text.substr(1,text.size()-1), pattern)));
        } else {
            return first_match && isMatch(text.substr(1,text.size()-1), pattern.substr(1,pattern.size()-1));
        }
    }
};