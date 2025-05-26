class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build the graph as adjacency list
        vector<vector<pair<int, int>>> graph(n);
        for (auto& f : flights) {
            graph[f[0]].push_back({f[1], f[2]});  // from -> {to, price}
        }

        // Min-heap: (total cost so far, current city, stops so far)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0});  // start with src, 0 cost, 0 stops

        // To avoid reprocessing expensive or longer paths
        vector<int> stops(n, INT_MAX);  // min stops to reach each city

        while (!pq.empty()) {
            auto [cost, city, step] = pq.top();
            pq.pop();

            // If destination reached, return cost
            if (city == dst) return cost;

            // If we already visited this city with fewer stops, skip
            if (step > stops[city] || step > k) continue;
            stops[city] = step;

            // Push neighbors
            for (auto& [next, price] : graph[city]) {
                pq.push({cost + price, next, step + 1});
            }
        }

        return -1;  // not reachable within k stops
    }
};
