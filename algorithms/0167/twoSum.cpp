class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> indice;
        if (numbers.empty() || numbers.size() < 2) return indice;
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int v = numbers[left] + numbers[right];
            if (v == target) {
                indice.push_back(left + 1);
                indice.push_back(right + 1);
                break;
            } else if (v > target) {
                right --;
            } else {
                left ++;
            }
        }
        return indice;
    }
};