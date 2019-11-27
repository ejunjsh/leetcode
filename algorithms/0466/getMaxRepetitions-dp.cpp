// Time: O(|s1| * n1) where |s1| is the length of s1
// Space: O(n1)
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> repeatCount(n1 + 1, 0);
        vector<int> nextIndex(n1 + 1, 0);
        int j = 0, cnt = 0;
        for (int k = 1; k <= n1; ++k) {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == s2[j]) {
                    ++j;
                    if (j == s2.size()) {
                        j = 0;
                        ++cnt;
                    }
                }
            }
            repeatCount[k] = cnt;
            nextIndex[k] = j;
            for (int start = 0; start < k; ++start) {
                if (nextIndex[start] == j) { // see if you have met this nextIndex before
                    // if found, you can calculate the 3 parts
                    int prefixCount = repeatCount[start]; // prefixCount is the start-th repeatCount
                    // (repeatCount[k] - prefixCount) is the repeatCount of one occurrance of the pattern
                    // There are (n1 - start) / (k - start) occurrances of the pattern
                    // So (n1 - start) / (k - start) * (repeatCount[k] - prefixCount) is the repeatCount of the repetitive part
                    int patternCount = (n1 - start) / (k - start) * (repeatCount[k] - prefixCount);
                    // The suffix contains the incomplete repetitive remnant (if any)
                    // Its length is (n1 - start) % (k - start)
                    // So the suffix repeatCount should be repeatCount[start + (n1 - start) % (k - start)] - prefixCount
                    int suffixCount = repeatCount[start + (n1 - start) % (k - start)] - prefixCount;
                    return (prefixCount + patternCount + suffixCount) / n2;
                }
            }
        }
        return repeatCount[n1] / n2;
    }
};