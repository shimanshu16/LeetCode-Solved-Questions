class Solution {
public:
    int t[601][101][101];
    int solve(int i, vector<string>& strs, int m, int n, map<string,pair<int,int>>& mp){
        if(i == strs.size())return 0;

        if(t[i][m][n] != -1)return t[i][m][n];
        cout << "h";

        int zero = mp[strs[i]].first, one = mp[strs[i]].second, take= 0;
        if(zero <= m && one <= n)take = 1 + solve(i+1, strs, m-zero, n-one, mp);
        int notTake = solve(i+1, strs, m, n, mp);

        return t[i][m][n] =  max(take, notTake);
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(t, -1, sizeof(t));
        map<string,pair<int,int>> mp;
        for(auto str: strs){
            int one = 0, zero = 0;
            for(int i = 0; i < str.length(); i++){
                if(str[i] == '1')one++;
                else zero++;
            }
            mp[str] = {zero, one};
        }

        return solve(0, strs, m, n, mp);
    }
};