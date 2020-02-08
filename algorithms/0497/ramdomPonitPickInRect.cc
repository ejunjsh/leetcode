class Solution {
public:
    Solution(vector<vector<int>> rects) {
        _rects = rects;
        _totalArea = 0;
        for (auto rect : rects) {
            _totalArea += (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            _areaToIdx.insert({_totalArea, _areaToIdx.size()});
        }
    }
    
    vector<int> pick() {
        int val = rand() % _totalArea;
        int idx = _areaToIdx.upper_bound(val)->second;
        int width = _rects[idx][2] - _rects[idx][0] + 1;
        int height = _rects[idx][3] - _rects[idx][1] + 1;
        return {rand() % width + _rects[idx][0], rand() % height + _rects[idx][1]};
    }

private:
    vector<vector<int>> _rects;
    int _totalArea;
    map<int, int> _areaToIdx;
};