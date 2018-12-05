class Solution{
    public:
        vector<int> twoSum(vector<int> &numbers,int target){
            unordered_map<int,int> m;
            vector<int> result;

            for(int i=0;i<numbers.size();i++){
                if(m.find(numbers[i])==m.end()){
                    m[target-numbers[i]]=i;
                }else{
                    result.push_back(m[numbers[i]]);
                    result.push_back(i);
                    break;
                }
            
            }
        return result;
        }
};