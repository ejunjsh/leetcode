class Solution{
    public:
        int threeSumClosest(vector<int>& nums,int target){
            if(nums.size() < 3) return 0;
            int closest = nums[0]+nums[1]+nums[2];
            sort(nums.begin(),nums.end());
            for(unsigned int i=0;i<nums.size()-2;i++){
                if(i>0&&nums[i]==nums[i-1])
                    continue;
                int l=i+1,r=nums.size()-1;
                while(l<r){
                    int s=nums[i]+nums[l]+nums[r];
                    if(abs(target-s)<abs(target-closest)) {
                        closest = s;
                    }
                    if(s>target) r--;
                    else if(s<target) l++;
                    else{
                        return s;
                    }
                }
            }
            return closest;
        }
};