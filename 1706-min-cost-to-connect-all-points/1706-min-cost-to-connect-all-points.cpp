class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();  // total number of points
        vector<bool> visited(n, false);  // to mark which points are already connected
        int cost = 0;  // total minimum cost to connect all points
        int edgesUsed = 0;  // number of connections we’ve made so far

        // Min-heap to store {cost, pointIndex}, so we always pick the lowest cost connection
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.push({0, 0});  // start from point 0 with 0 cost

        while (edgesUsed < n) {
            auto [currCost, u] = minHeap.top();  // get the point with the least connection cost
            minHeap.pop();

            // If the point is already connected, skip it
            if (visited[u]) continue;

            visited[u] = true;  // mark the point as connected
            cost += currCost;   // add the cost
            edgesUsed++;        // we’ve used one more connection

            // Now try connecting this point to all other unvisited points
            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    // Manhattan distance between points u and v
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minHeap.push({dist, v});  // add this edge to the heap
                }
            }
        }

        return cost;  // return the total minimum cost to connect all points
    }
};