class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto comp = [](const vector<int>& i1, const vector<int>& i2){ return i1[0] < i2[0]; };
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0, pre = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[pre][1]) {
                res++;
                if (intervals[i][1] < intervals[pre][1]) pre = i;
            }
            else pre = i;
        }
        return res;
    }
};