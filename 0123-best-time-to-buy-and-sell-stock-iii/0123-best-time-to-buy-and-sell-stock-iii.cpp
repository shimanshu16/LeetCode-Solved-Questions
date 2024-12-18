class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp; 

    int h(int i, int t, int can_buy, vector<int>& prices) {
        if (i == n || t == 2) 
        return 0;

        if (dp[i][t][can_buy] != -1) 
        return dp[i][t][can_buy];
        
        int profit = h(i + 1, t, can_buy, prices);

        if (can_buy) 
        profit = max(profit, -prices[i] + h(i + 1, t, 0, prices));
        else 
        profit = max(profit, prices[i] + h(i + 1, t + 1, 1, prices));
        
        return dp[i][t][can_buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return h(0, 0, 1, prices);  
    }
};