class Solution{
    public:
        bool isValidSudoku(vector<vector<char>> &board){
            int r[9][9]={0},c[9][9]={0},b[9][9]={0};

            for(int i = 0; i < 9; ++ i)
            for(int j = 0; j < 9; ++ j)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '0' - 1, k = i / 3 * 3 + j / 3;
                    if(r[i][num] || c[j][num] || b[k][num])
                        return false;
                    r[i][num] = c[j][num] = b[k][num] = 1;
                }
        
            return true;
        }   
};