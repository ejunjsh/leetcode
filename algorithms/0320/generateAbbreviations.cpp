class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        res.push_back(word.size() == 0 ? "" : to_string(word.size()));
        for (int i = 0; i < word.size(); ++i) {
            for (auto a : generateAbbreviations(word.substr(i + 1))) {
                string left = i > 0 ? to_string(i) : "";
                res.push_back(left + word.substr(i, 1) + a);
            }
        }
        return res;
    }
};