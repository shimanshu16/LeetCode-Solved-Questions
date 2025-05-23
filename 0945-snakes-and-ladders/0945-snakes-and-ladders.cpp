#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        // Helper function to convert 2D board position to 1D index
        auto getCoordinates = [&](int num) {
            int row = (num - 1) / n;
            int col = (num - 1) % n;
            if (row % 2 == 1) col = n - 1 - col; // reverse direction for odd rows
            return make_pair(n - 1 - row, col);
        };

        queue<pair<int, int>> q; // {cell number, number of moves}
        q.push({1, 0}); // start from cell 1 with 0 moves
        vector<bool> visited(n * n + 1, false);
        visited[1] = true;

        while (!q.empty()) {
            auto [cell, moves] = q.front();
            q.pop();

            // Try all 6 possible dice rolls
            for (int dice = 1; dice <= 6; ++dice) {
                int nextCell = cell + dice;
                if (nextCell > n * n) break;

                auto [row, col] = getCoordinates(nextCell);
                // If there's a snake or ladder, move to that cell
                if (board[row][col] != -1) {
                    nextCell = board[row][col];
                }

                // If we reached the end
                if (nextCell == n * n) return moves + 1;

                // If not visited, add to queue
                if (!visited[nextCell]) {
                    visited[nextCell] = true;
                    q.push({nextCell, moves + 1});
                }
            }
        }

        // If we can't reach the last cell
        return -1;
    }
};
