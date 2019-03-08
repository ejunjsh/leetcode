class Solution {
public:
    int maximumGap(vector<int> &numss) {
        if (numss.empty()) return 0;
        int mx = INT_MIN, mn = INT_MAX, n = numss.size();
        for (int d : numss) {
            mx = max(mx, d);
            mn = min(mn, d);
        }
        int size = (mx - mn) / n + 1;
        int bucket_nums = (mx - mn) / size + 1;
        vector<int> bucket_min(bucket_nums, INT_MAX);
        vector<int> bucket_max(bucket_nums, INT_MIN);
        set<int> s;
        for (int d : numss) {
            int idx = (d - mn) / size;
            bucket_min[idx] = min(bucket_min[idx], d);
            bucket_max[idx] = max(bucket_max[idx], d);
            s.insert(idx);
        }
        int pre = 0, res = 0;
        for (int i = 1; i < n; ++i) {
            if (!s.count(i)) continue;
            res = max(res, bucket_min[i] - bucket_max[pre]);
            pre = i;
        }
        return res;
    }
};