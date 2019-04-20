class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int candidate1 = 0, candidate2 = 0, count1 = 0, count2 = 0;
        for (auto &a : nums) {
            if (a == candidate1) ++count1;
            else if (a ==candidate2) ++count2;
            else if (count1 == 0) candidate1 = a, count1 = 1;
            else if (count2 == 0) candidate2 = a, count2 = 1;
            else --count1, --count2;
        }
        count1 = count2 = 0;
        for (auto &a : nums) {
            if (a == candidate1) ++count1;
            else if (a == candidate2) ++count2;
        }
        if (count1 > nums.size() / 3) res.push_back(candidate1);
        if (count2 > nums.size() / 3) res.push_back(candidate2);
        return res;
    }
};