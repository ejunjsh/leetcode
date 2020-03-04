class Solution {
public:
    Solution(int n_rows, int n_cols) {
        row = n_rows; col = n_cols;
        size = row * col;
    }
    
    vector<int> flip() {
        int id = rand() % size, val = id;
        --size;
        if (m.count(id)) id = m[id];
        m[val] = m.count(size) ? m[size] : size;
        return {id / col, id % col};
    }
    
    void reset() {
        m.clear();
        size = row * col;
    }

private:
    int row, col, size;
    unordered_map<int, int> m;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */