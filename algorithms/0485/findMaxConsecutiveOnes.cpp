class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res=0,p=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                p=0;
            }else{
                p++;
            }
            
            res=max(res,p);
        }
        return res;
    }
};