class Solution {
private:
    vector<int> nums;
    
public:
    Solution(vector<int>& nums) {
        this->nums=nums;
    }
    
    int pick(int target) {
        int n = 0, res = -1;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] != target) continue;
            if(n == 0){res = i; n++;}
            else{
                n++;
                if(rand() % n == 0){res = i;}
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */