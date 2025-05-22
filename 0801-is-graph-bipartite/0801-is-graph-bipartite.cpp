#include <vector>
using namespace std;

class Solution {
public:
    bool dfs(int node, int c, vector<vector<int>>& graph, vector<int>& color) {
        color[node] = c;  // Color the current node

        // Visit all the neighbors of the current node
        for (int neighbor : graph[node]) {
            // If neighbor is not colored, color it with opposite color
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - c, graph, color)) {
                    return false;  // If we find a conflict, return false
                }
            }
            // If neighbor is already colored with the same color → not bipartite
            else if (color[neighbor] == color[node]) {
                return false;
            }
        }
        return true;  // No conflict found for this path
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // -1 means unvisited

        // Loop through all nodes (important for disconnected graphs)
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                // Start DFS with color 0
                if (!dfs(i, 0, graph, color)) {
                    return false;
                }
            }
        }
        return true;  // All components are bipartite
    }
};
