class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int coolDown=0, sell=0, hold=std::numeric_limits<int>::min();
        
        for( int stockPrice_Day_i : prices){
            
            int prevCoolDown = coolDown, prevSell = sell, prevHold = hold;
            coolDown = max(prevCoolDown, prevSell);
            sell = prevHold + stockPrice_Day_i;
            hold = max(prevHold, prevCoolDown - stockPrice_Day_i);
            
        }
        
        return max( sell, coolDown );
    }
};