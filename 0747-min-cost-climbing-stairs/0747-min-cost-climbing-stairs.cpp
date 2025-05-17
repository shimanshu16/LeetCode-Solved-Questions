#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        std::vector<int> minCost(n + 1, 0);

        for (int i = 2; i <= n; ++i) {
            minCost[i] = std::min(
                cost[i - 1] + minCost[i - 1],
                cost[i - 2] + minCost[i - 2]
            );
        }

        return minCost[n];
    }
};
