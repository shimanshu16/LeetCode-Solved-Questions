class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;

        int dx[] = {0, 0, 0, 1, -1};
        int dy[] = {0, 1, -1, 0, 0};

        dq.emplace_back(0, 0);
        cost[0][0] = 0;

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (int dir = 1; dir <= 4; ++dir) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = cost[x][y] + (grid[x][y] != dir);

                    if (newCost < cost[nx][ny]) {
                        cost[nx][ny] = newCost;

                        if (grid[x][y] == dir) {
                            dq.emplace_front(nx, ny); 
                        } else {
                            dq.emplace_back(nx, ny); 
                        }
                    }
                }
            }
        }

        return cost[m - 1][n - 1];
    }
};