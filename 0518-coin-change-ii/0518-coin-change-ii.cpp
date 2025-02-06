class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;
        
        for(int coin = n - 1;coin >=0;coin--){
            for(int target = 0;target <= amount;target++){
                if(target >= coins[coin]){
                    dp[target] += dp[target - coins[coin]];
                }
            }
        }
        return dp[amount];
    }
};