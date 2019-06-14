// example: 1 3 5 7
// 
//            [0, 3]
//              16
//        /            \
//     [0, 1]        [2, 3]
//       4             12
//    /     \       /     \
// [0, 0] [1, 1] [2, 2] [3, 3]
//    1      3      5      7
class NumArray {
public:
    NumArray(vector<int> nums) {
        n = nums.size();
        tree.resize(n * 2);
        buildTree(nums);
    }

    void buildTree(vector<int>& nums) {
        for (int i = n; i < n * 2; ++i) {
            tree[i] = nums[i - n];
        }
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }

    void update(int i, int val) {
        tree[i += n] = val;
        while (i > 0) {
            tree[i / 2] = tree[i] + tree[i ^ 1];
            i /= 2;
        }
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for (i += n, j += n; i <= j; i /= 2, j /= 2) {
            if ((i & 1) == 1) sum += tree[i++];
            if ((j & 1) == 0) sum += tree[j--];
        }
        return sum;
    }    

private:
    int n;
    vector<int> tree;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */