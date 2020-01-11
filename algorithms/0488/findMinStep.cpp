class Solution {
public:
    int findMinStep(string board, string hand) {
        int res = INT_MAX;
        unordered_set<char> s;
        for (int i = 0; i < hand.size(); ++i) {
            if (s.count(hand[i])) continue;
            s.insert(hand[i]);
            for (int j = 0; j < board.size(); ++j) {
                if (board[j] != hand[i]) continue;
                string newBoard = board, newHand = hand;
                newBoard.insert(j, 1, hand[i]);
                newBoard = removeConsecutive(newBoard);
                if (newBoard.size() == 0) return 1;
                newHand.erase(i, 1);
                int cnt = findMinStep(newBoard, newHand);
                if (cnt != -1) res = min(res, cnt + 1);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
    string removeConsecutive(string board) {
        for (int i = 0, j = 0; i <= board.size(); ++i) {
            if (i < board.size() && board[i] == board[j]) continue;
            if (i - j >= 3) return removeConsecutive(board.substr(0, j) + board.substr(i));
            else j = i;
        }
        return board;
    }
};