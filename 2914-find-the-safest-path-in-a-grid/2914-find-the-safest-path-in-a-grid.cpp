#include <vector>
#include <queue>
#include <algorithm> // for max, min
#include <climits>   // for INT_MAX
using namespace std;

class Solution {
public:
    // Directions for moving up, down, left, right
    vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
    // Function to calculate distance of every cell from nearest dangerous cell (bomb)
    vector<vector<int>> calcDistanceFromDanger(const vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        queue<pair<int,int>> q;
        
        // Start BFS from all dangerous cells (where grid[i][j] == 1)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // BFS to fill dist with shortest distance to danger
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (auto &dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    if (dist[nr][nc] > dist[r][c] + 1) {
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return dist;
    }
    
    // Check if a path exists from top-left to bottom-right
    // where all cells have distance >= minSafety
    bool canReachWithSafety(const vector<vector<int>>& dist, int minSafety) {
        int rows = dist.size();
        int cols = dist[0].size();
        
        if (dist[0][0] < minSafety) return false; // start cell not safe enough
        
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            if (r == rows-1 && c == cols-1) return true; // reached destination
            
            for (auto &dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    if (!visited[nr][nc] && dist[nr][nc] >= minSafety) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Calculate the minimum distance from danger for every cell
        vector<vector<int>> dist = calcDistanceFromDanger(grid);
        
        // Step 2: Binary search on safety factor
        int left = 0;
        int right = *max_element(
            dist[0].begin(), dist[0].end()); // initial max guess
        for (int i = 1; i < rows; i++) {
            right = max(right, *max_element(dist[i].begin(), dist[i].end()));
        }
        
        int answer = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canReachWithSafety(dist, mid)) {
                answer = mid; // we can achieve at least mid safety
                left = mid + 1; // try for higher safety
            } else {
                right = mid - 1; // lower safety needed
            }
        }
        
        return answer;
    }
};
