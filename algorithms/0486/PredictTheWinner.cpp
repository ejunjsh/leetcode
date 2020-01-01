class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return winner(nums, 0, nums.size() - 1, 1) >= 0;
    }
    
    int winner(vector<int>& nums, int s, int e, int turn) {
        if (s == e)
            return turn * nums[s];
        int a = turn * nums[s] + winner(nums, s + 1, e, -turn);
        int b = turn * nums[e] + winner(nums, s, e - 1, -turn);
        return turn * max(turn * a, turn * b);
    }
};