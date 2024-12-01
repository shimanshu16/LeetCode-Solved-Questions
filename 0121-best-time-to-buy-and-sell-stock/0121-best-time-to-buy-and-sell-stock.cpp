class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrices = INT_MAX;
        int maxProfit = 0;

        for (int prices : prices){
           minPrices = min(minPrices, prices);
           maxProfit = max(maxProfit, prices - minPrices);
        }
        return maxProfit;
    }
};