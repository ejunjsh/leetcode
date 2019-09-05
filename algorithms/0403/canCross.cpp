class Solution {
public:
    bool canCross(vector<int>& stones, int pos = 0, int k = 0) {
        for (int i = pos + 1; i < stones.size(); i++) {
            int gap = stones[i] - stones[pos];
            if (gap < k - 1) continue;
            if (gap > k + 1) return false;
            if (canCross(stones, i, gap)) return true;
        }
        return pos == stones.size() - 1;
    }
};