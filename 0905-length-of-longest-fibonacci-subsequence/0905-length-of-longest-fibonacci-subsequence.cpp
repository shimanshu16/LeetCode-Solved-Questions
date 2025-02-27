int dp[1000][1000];
class Solution {
public:
    static int lenLongestFibSubseq(vector<int>& arr) {
        const int n=arr.size();
        unordered_map<int, int> x2i;
        x2i.reserve(n);
        fill(&dp[0][0], &dp[0][0]+n*1000, 2);
        int ans=0;
        
        for (int i=0; i < n; i++) 
            x2i[arr[i]]=i;

        for (int i1=1; i1<n-1; i1++) {
            int f1=arr[i1];
            for (int i2=i1+1; i2<n; i2++) {
                int f2=arr[i2];
                int f0=f2-f1; 
                if (f0>=f1) break; 
                if (x2i.count(f0)) { 
                    int i0=x2i[f0];
                    dp[i1][i2]=dp[i0][i1]+1;
                }

                ans=max(ans, dp[i1][i2]); 
            }
        }

        return ans>2?ans:0;
    }
};