class Solution {
public:
    string parseTernary(string expression) {
        string res = expression;
        while (res.size() > 1) {
            int i = res.find_last_of("?");
            res = res.substr(0, i - 1) + string(1, res[i - 1] == 'T' ? res[i + 1] : res[i + 3]) + res.substr(i + 4);
        }
        return res;
    }
};