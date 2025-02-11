class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        
        vector<vector<int>> visited(m , vector<int>(n , 0));
        int dir[4][2] = {{1, 0 } , {-1 , 0} , {0 , 1} , {0 , -1}};
        queue<pair<pair<int,int> , int>> q;
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0){
                    visited[i][j] = 1;
                    q.push({{i , j} , 0});
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first , c = q.front().first.second , x = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nr = r + dir[i][0] , nc = c + dir[i][1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]){
                    mat[nr][nc] = x+1;
                    q.push({{nr,nc} , x+1 });
                    visited[nr][nc] = 1;
                }
            }
        }

        return mat;
    }
};