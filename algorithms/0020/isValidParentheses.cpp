class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char& c : s) {
            switch (c) {
                case '(': 
                case '{': 
                case '[': stack.push(c); break;
                case ')': if (stack.empty() || stack.top()!='(') return false; else stack.pop(); break;
                case '}': if (stack.empty() || stack.top()!='{') return false; else stack.pop(); break;
                case ']': if (stack.empty() || stack.top()!='[') return false; else stack.pop(); break;
                default: ; 
            }
        }
        return stack.empty() ;
    }
};