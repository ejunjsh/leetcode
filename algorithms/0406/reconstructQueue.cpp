// given：
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// sorted：
// [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
// inserted：
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        vector<vector<int>> res;
        for (auto a : people) {
            res.insert(res.begin() + a[1], a);
        }
        return res;
    }
};