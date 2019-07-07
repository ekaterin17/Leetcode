class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int row = -1, col = -1, count = 0;
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board.size(); ++j) {
                if(board[i][j] == 'R') {
                    row = i, col = j; 
                    break;
                }
            }
            if (row >= 0 && col >= 0) {
                break;
            }
        }
                
        for (int i = row + 1; i < board.size(); ++i) {
            if (board[i][col] == 'p') {
                count++;
                break;
            } else if (board[i][col] != '.') {
                break;
            }
        }
        
        for(int i = row - 1; i >= 0; --i) {
            if (board[i][col] == 'p') {
                count++;
                break;
            } else if (board[i][col] != '.') {
                break;
            }
        }
        
        for(int j = col + 1; j < board.size(); j++){
            if (board[row][j] == 'p') {
                count++;
                break;
            } else if(board[row][j] != '.') {
                break;
            }
        }
        
        for(int j = col - 1; j >= 0; j--){
            if (board[row][j] == 'p') {
                count++;
                break;
            } else if(board[row][j] != '.') {
                break;
            }
        }
        
        return count;
    }
};
