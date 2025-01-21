class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        queue<string> q;
        q.push(startGene);
        int ans = 1;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string gene = q.front();
                q.pop();

                for (auto it = bankSet.begin(); it != bankSet.end(); ) {
                    string b = *it;
                    int diff = 0;
                    for (int j = 0; j < 8 && diff < 2; ++j) {
                        diff += (gene[j] == b[j]) ? 0 : 1;
                    }

                    if (diff == 1) {
                        if (b == endGene) {
                            return ans;
                        }
                        q.push(b);
                        it = bankSet.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
            ++ans;
        }
        return -1;
    }
};