class Solution {
public:

    vector<vector<int>> dp;

    int solve(string& s,int i,int j){
        if(i==j) return 1;
        if(i>j) return 0;

       if(dp[i][j]!=-1){
          return dp[i][j];
       }

        if(s[i]==s[j]) return dp[i][j] =2+solve(s,i+1,j-1);
        int leaveLeft=solve(s,i+1,j);
        int leaveRight=solve(s,i,j-1);

        return dp[i][j]=max(leaveLeft,leaveRight);
    }

    int longestPalindromeSubseq(string s) {
        dp.assign(s.size(),vector<int>(s.size(),-1));
        return solve(s,0,s.size()-1);
    }
};