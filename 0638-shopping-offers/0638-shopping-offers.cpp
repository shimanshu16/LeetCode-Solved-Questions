class Solution {
public:
    unordered_map<string, int> memo;

    string encode(const vector<int>& needs) {
        string key;
        for (int need : needs) {
            key += to_string(need) + ",";
        }
        return key;
    }

    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        string key = encode(needs);
        if (memo.count(key)) return memo[key];

        int minCost = 0;
        for (int i = 0; i < needs.size(); ++i) {
            minCost += needs[i] * price[i];
        }

        for (auto& offer : special) {
            vector<int> newNeeds = needs;
            bool valid = true;
            for (int i = 0; i < needs.size(); ++i) {
                if (offer[i] > needs[i]) {
                    valid = false;
                    break;
                }
                newNeeds[i] -= offer[i];
            }
            if (valid) {
                minCost = min(minCost, offer.back() + solve(price, special, newNeeds));
            }
        }

        return memo[key] = minCost;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price, special, needs);
    }
};