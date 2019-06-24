class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, bool> visited;
        unordered_map<char, int> counter;
        string result = "";
        for (auto c : s) counter[c]++;
        for (auto c : s) {
            counter[c]--;
            if (visited[c]) continue;  
            while (!result.empty() && c < result.back() && counter[result.back()] > 0) {
                visited[result.back()] = false;
                result.pop_back();
            }
            result += c;
            visited[c] = true;
        }
        return result;
    }
};