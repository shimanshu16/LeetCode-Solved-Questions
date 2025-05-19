class Solution {
public:
    int maxJump(vector<int>& stones) {
        int maxJump = 0;

        // Case 1: Jump every two stones starting from index 0 (0 -> 2 -> 4 -> ...)
        for (int i = 0; i + 2 < stones.size(); i++) {
            maxJump = max(maxJump, stones[i + 2] - stones[i]);
        }

        // Case 2: Jump every two stones starting from index 1 (1 -> 3 -> 5 -> ...)
        for (int j = 1; j + 2 < stones.size(); j++) {
            maxJump = max(maxJump, stones[j + 2] - stones[j]);
        }

        // Also check the direct jump from stone[0] to stone[1]
        maxJump = max(maxJump, stones[1] - stones[0]);

        return maxJump;
    }
};
