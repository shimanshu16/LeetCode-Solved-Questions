class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // Set to store all deadends (blocked combinations)
        unordered_set<string> dead(deadends.begin(), deadends.end());

        // If starting point is a deadend, we can’t move
        if (dead.count("0000")) return -1;

        // Queue for BFS. It stores the lock combinations
        queue<string> q;
        q.push("0000");

        // Set to keep track of visited combinations to avoid loops
        unordered_set<string> visited;
        visited.insert("0000");

        int steps = 0; // This counts how many moves we’ve made

        while (!q.empty()) {
            int size = q.size(); // Number of combinations at current level (step)

            // Go through all combinations in current level
            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();

                // If we reached the target, return number of steps
                if (current == target) return steps;

                // Try all 8 possible next moves (turn each wheel up or down)
                for (int j = 0; j < 4; j++) {
                    string up = current;
                    string down = current;

                    // Turn the j-th wheel one step up (e.g. 9 → 0)
                    up[j] = (current[j] == '9') ? '0' : current[j] + 1;

                    // Turn the j-th wheel one step down (e.g. 0 → 9)
                    down[j] = (current[j] == '0') ? '9' : current[j] - 1;

                    // If new combination is not visited and not dead, add to queue
                    if (!dead.count(up) && !visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }

                    if (!dead.count(down) && !visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }

            // After exploring one level (all combinations in this step), increase step
            steps++;
        }

        // If we never reach the target, return -1
        return -1;
    }
};
