#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // DFS function to calculate total time taken to inform all subordinates
    int dfs(int managerId, unordered_map<int, vector<int>>& tree, vector<int>& informTime) {
        int maxTime = 0;

        // Go through each direct employee of the current manager
        for (int employee : tree[managerId]) {
            // Recursively calculate time for each employee
            maxTime = max(maxTime, dfs(employee, tree, informTime));
        }

        // Add current manager's inform time to the maximum time of subordinates
        return informTime[managerId] + maxTime;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // Create a tree (adjacency list) to store who reports to whom
        unordered_map<int, vector<int>> tree;

        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                tree[manager[i]].push_back(i); // manager[i] is the boss of employee i
            }
        }

        // Start DFS from the head of the company
        return dfs(headID, tree, informTime);
    }
};
