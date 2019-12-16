class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int res = 0;
        sort(heaters.begin(), heaters.end());
        for (int house : houses) {
            auto pos = lower_bound(heaters.begin(), heaters.end(), house);
            int dist1 = (pos == heaters.end()) ? INT_MAX : *pos - house;
            int dist2 = (pos == heaters.begin()) ? INT_MAX : house - *(--pos);
            res = max(res, min(dist1, dist2));
        }
        return res;
    }
};