#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create a 2D distance matrix and initialize with large values (infinity)
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Distance from a city to itself is zero
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        
        // Fill the distance matrix with direct edges distances
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        
        // Floyd-Warshall Algorithm to find shortest distance between all pairs of cities
        for (int k = 0; k < n; k++) {           // For each intermediate city k
            for (int i = 0; i < n; i++) {       // For each starting city i
                for (int j = 0; j < n; j++) {   // For each ending city j
                    // If going through city k is shorter, update distance[i][j]
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX 
                        && dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        
        int resultCity = 0;  // To store city with smallest neighbors
        int smallestCount = n;  // Initialize with max possible neighbors
        
        // Count reachable cities within distanceThreshold for each city
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                // If distance is less than or equal to threshold, city j is reachable from city i
                if (dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            
            // Update result if current city has fewer or equal reachable cities
            // In case of tie, pick city with bigger number
            if (count <= smallestCount) {
                smallestCount = count;
                resultCity = i;
            }
        }
        
        return resultCity;
    }
};
