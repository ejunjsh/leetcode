class SummaryRanges {
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        auto it = st.lower_bound({val, val});
        int start = val, end = val;
        if(it != st.begin() && (*(--it))[1]+1 < val) it++;
        while(it != st.end() && val+1 >= (*it)[0] && val-1 <= (*it)[1])
        {
            start = min(start, (*it)[0]);
            end = max(end, (*it)[1]);
            it = st.erase(it);
        }
        st.insert(it,{start, end});
    }
    
    vector<vector<int>> getIntervals() {
         vector<vector<int>> result;
        for(auto val: st) result.push_back(val);
        return result;
    }
    
private:
    set<vector<int>> st;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */