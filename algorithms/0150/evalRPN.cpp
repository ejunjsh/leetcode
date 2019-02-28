class Solution
{
public:
    int evalRPN(vector<string> & tokens)
    {
        string s = tokens.back(); tokens.pop_back();
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int b = evalRPN(tokens);
            int a = evalRPN(tokens);
            if (s == "+") return a + b;
            if (s == "-") return a - b;
            if (s == "*") return a * b;
            if (s == "/") return a / b;
            assert(false);
        }
        else
            return stoi(s);
    }
};