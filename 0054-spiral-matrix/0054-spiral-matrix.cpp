class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int srow = 0, scol =0;
        int erow = matrix.size() - 1, ecol = matrix[0].size() -1;

        while (srow <= erow && scol <= ecol) {
            // top
            for (int j = scol; j <= ecol; j++){
                result.push_back(matrix[srow][j]);
            }
            // right
            for(int i = srow + 1; i <= erow; i++){
                result.push_back(matrix[i][ecol]);
            }
            // bottom
            for (int j = ecol-1; j >= scol; j--){
                if ( srow == erow){
                    break;
                }
                result.push_back(matrix[erow][j]);
            }
            //left
            for (int i = erow-1; i >= srow +1; i--){
                if (scol == ecol){
                    break;
                }
                result.push_back(matrix[i][scol]);
            }

            srow++; 
            scol++;
            erow--; 
            ecol--;
        }
        return result;
    }
};