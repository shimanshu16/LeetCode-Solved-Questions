#include <vector>
#include <queue>
#include <cmath>     // for abs()
#include <climits>   // for INT_MAX
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // Create a 2D array to store minimum effort required to reach each cell
        vector<vector<int>> effort(rows, vector<int>(cols, INT_MAX));
        effort[0][0] = 0; // Starting point requires 0 effort

        // Min-heap priority queue to always pick the cell with the smallest effort
        priority_queue< pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>, 
                        greater<pair<int, pair<int, int>>> > pq;

        // Push starting cell into the queue: {effort, {row, col}}
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [currentEffort, cell] = pq.top();
            pq.pop();

            int r = cell.first;
            int c = cell.second;

            // If we reached the bottom-right cell, return the effort
            if (r == rows - 1 && c == cols - 1) {
                return currentEffort;
            }

            // Check all 4 directions
            for (auto dir : directions) {
                int newRow = r + dir.first;
                int newCol = c + dir.second;

                // Check if the new cell is inside the grid
                if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols) {
                    // Calculate the effort to move to the neighbor
                    int heightDiff = abs(heights[newRow][newCol] - heights[r][c]);
                    int maxEffort = max(currentEffort, heightDiff);

                    // If this path gives a smaller effort, update and push to queue
                    if (maxEffort < effort[newRow][newCol]) {
                        effort[newRow][newCol] = maxEffort;
                        pq.push({maxEffort, {newRow, newCol}});
                    }
                }
            }
        }

        // This line will never be reached due to return inside loop
        return 0;
    }
};
