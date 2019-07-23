class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        vector<int> vals={val,val};
        auto it = lower_bound(vec.begin(), vec.end(), vals);
        int start = val, end = val;
        if(it != vec.begin() && (*(it-1))[1]+1 >= val) it--;
        while(it != vec.end() && val+1 >= (*it)[0] && val-1 <= (*it)[1])
        {
            start = min(start, (*it)[0]);
            end = max(end, (*it)[1]);
            it = vec.erase(it);
        }
        vec.insert(it,{start, end});
    }
    
    vector<vector<int>> getIntervals() {
        return vec;
    }
    
private:
    vector<vector<int>> vec;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */