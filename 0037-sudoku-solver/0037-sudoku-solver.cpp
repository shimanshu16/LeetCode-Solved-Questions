class Solution {
private:

    bool isThisPlacementValidAtThisIndex(vector<vector<char>>& board, int row, int col, char placement) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == placement) {
                return false;
            }
            if(board[row][i] == placement) {
                return false;
            }
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == placement) {
                return false;
            }
        }
        return true; 
    }
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
            
                if(board[i][j] == '.') {
                
                    for(char placement = '1'; placement <= '9'; placement++) {
                        if(isThisPlacementValidAtThisIndex(board, i, j, placement)) {
                            board[i][j] = placement;
                            if(solve(board)) {
                                return true;
                            }
                            board[i][j] = '.'; 
                        }
                    }
                    return false; 
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};