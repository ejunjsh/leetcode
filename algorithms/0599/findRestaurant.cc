class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        unordered_map<string, int> m;
        int mn = INT_MAX, n1 = list1.size(), n2 = list2.size();
        for (int i = 0; i < n1; ++i) m[list1[i]] = i;
        for (int i = 0; i < n2; ++i) {
            if (m.count(list2[i])) {
                int sum = i + m[list2[i]];
                if (sum == mn) res.push_back(list2[i]);
                else if (sum < mn) {
                    mn = sum;
                    res = {list2[i]};
                }
            }
        }
        return res;
    }
};