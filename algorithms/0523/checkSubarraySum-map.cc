class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        unordered_map<int, int> m{{0,-1}};
        for(int i=0;i<n;++i){
            sum+=nums[i];
            int t = k==0?sum:(sum%k);
            if(m.count(t)){
                if(i-m[t]>1)
                    return true;
            }
            else{
                m[t]=i;
            }
        }
        return false;
    }
};