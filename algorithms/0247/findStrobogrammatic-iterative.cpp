class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> odd{"0", "1", "8"}, even{""}, res = even;
        if (n % 2 == 1) res = odd;
        for (int i = (n % 2) + 2; i <= n; i += 2) {
            vector<string> t;
            for (auto a : res) {
                if (i != n) t.push_back("0" + a + "0");
                t.push_back("1" + a + "1");
                t.push_back("6" + a + "9");
                t.push_back("8" + a + "8");
                t.push_back("9" + a + "6");
            }
            res = t;
        }
        return res;
    }
};