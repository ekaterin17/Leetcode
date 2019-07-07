class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int sum = 0;
        int row = board.size();
        int col = board[0].size();
        
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                bool flag1 = true, flag2 = true;
                if(board[i][j] == 'X') {
                    if (i-1 >= 0 && board[i-1][j] == 'X') {
                        flag1 = false;
                    }
                    if (j-1 >= 0 && board[i][j-1] == 'X') {
                        flag2 = false;
                    }
                    if (flag1 && flag2) {
                        ++sum; 
                    }
                }
            }
        }
        return sum;
    }
};
