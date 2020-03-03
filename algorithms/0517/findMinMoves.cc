class Solution {
public:
    int findMinMoves(vector<int>& machines) {
         int sum = accumulate(machines.begin(), machines.end(), 0);
        if (sum % machines.size() != 0) return -1;
        int res = 0, cnt = 0, avg = sum / machines.size();
        for (int m : machines) {
            cnt += m - avg;
            res = max(res, max(abs(cnt), m - avg));
        }
        return res;
    }
};