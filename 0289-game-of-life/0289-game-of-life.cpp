class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> count_live(m, vector<int>(n,0));
    
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1){  
                    if(i>0) count_live[i-1][j]++; 
                    if(i<m-1) count_live[i+1][j]++; 
                    if(j>0) count_live[i][j-1]++; 
                    if(j<n-1) count_live[i][j+1]++; 
                    if(i>0 && j>0) count_live[i-1][j-1]++; 
                    if(i>0 && j<n-1) count_live[i-1][j+1]++; 
                    if(i<m-1 && j>0) count_live[i+1][j-1]++; 
                    if(i<m-1 && j<n-1) count_live[i+1][j+1]++;
                }
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 1){  
                    if(count_live[i][j] < 2 || count_live[i][j] > 3) board[i][j] =0;
                } else{ 
                    if(count_live[i][j] == 3) board[i][j] = 1;
                }
            }
        }
    }
};