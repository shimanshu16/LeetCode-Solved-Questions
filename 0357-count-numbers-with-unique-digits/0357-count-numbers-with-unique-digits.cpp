class Solution {
public:

    int countNumbersWithUniqueDigits(int n) {
        
        vector<int> dp(n+1);
        dp[0] = 1;
        if(n >= 1)dp[1] = 10;
        for(int i = 2; i <= n; i++){
            int fact = 9;
            int s = i, tmp = 9;
            while(s > 1){
                tmp *= fact;
                fact--;
                s--;
            }
            dp[i] = tmp + dp[i-1];
            cout << dp[i] << " ";
        }

        return dp[n];

    }
};