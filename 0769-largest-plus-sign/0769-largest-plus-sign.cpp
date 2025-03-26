class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int ans=0,s,i,j,k;
        int dp[N+2][N+2][4],v[N][N];
        for(i=0;i<N;i++)for(j=0;j<N;j++)v[i][j]=1;
        for(i=0;i<mines.size();i++)v[mines[i][0]][mines[i][1]]=0;
        memset(dp,0,sizeof dp);
        
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(v[i][j]==1){
                    dp[i+1][j+1][0]=dp[i][j+1][0]+1;
                    dp[i+1][j+1][1]=dp[i+1][j][1]+1;
                }
            }
        }
        for(i=N-1;i>=0;i--){
            for(j=N-1;j>=0;j--){
                if(v[i][j]==1){
                    dp[i+1][j+1][2]=dp[i+2][j+1][2]+1;
                    dp[i+1][j+1][3]=dp[i+1][j+2][3]+1;
                }
            }
        }
        for(i=1;i<=N;i++){
            for(j=1;j<=N;j++){
                s=min(dp[i][j][0],min(dp[i][j][1],min(dp[i][j][2],dp[i][j][3])));
                ans=max(ans,s);
            }
        }
        return ans;
    }
};