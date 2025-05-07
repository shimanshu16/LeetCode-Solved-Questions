class Solution {
public:
    int mod=1e9+7;
    long long helper(string &s, int i,vector<int> &dp){
        if(i>=s.size()) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        long long ans=0;
        if(s[i]=='*'){
            ans+= 9*helper(s,i+1,dp);
            if(i+1<s.size()){
                if(s[i+1]=='*'){
                    ans+=15*helper(s,i+2,dp);
                }
                else if(s[i+1]<='6' && s[i+1]>='0'){
                    ans+=2*helper(s,i+2,dp);
                }
                else
                    ans+=helper(s,i+2,dp);
            }
            
        }
        else{
            ans+=helper(s,i+1,dp);
            if(i+1<s.size()){
                if(s[i]=='1'){
                    if(s[i+1]=='*'){
                        ans+=9*helper(s,i+2,dp);
                    }
                    else ans+=helper(s,i+2,dp);
                }
                if(s[i]=='2'){
                    if(s[i+1]=='*'){
                        ans+=6*helper(s,i+2,dp);
                    }
                    else if(s[i+1]>='0' && s[i+1]<='6'){
                        ans+=helper(s,i+2,dp);
                    }
                }
            }
        }
        return dp[i]=ans%mod;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,-1);
        return (int)helper(s,0,dp);
    }
};