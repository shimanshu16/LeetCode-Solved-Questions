class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                int minSum = min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                int currentVal = triangle[i][j];
                triangle[i][j] = currentVal + minSum;
            }
        }
        return triangle[0][0];
    }
};