class Solution {
public:
    int dp[2005][2005];
    bool f(vector<int>& a, int index, int prevInd) {
        int n = a.size();
        if (index == n - 1) return true;

        if(dp[index][prevInd] != -1) return dp[index][prevInd];

        int k = a[index] - a[prevInd];
        bool op1 = 0, op2 = 0, op3 = 0;
        if (k > 1) {
            int x = lower_bound(a.begin(), a.end(), a[index] + k - 1) - a.begin();
            if (x >= 0 && x < n && a[x] == a[index] + k - 1) {
                op1 = f(a, x, index);
            }
        }
        int y = lower_bound(a.begin(), a.end(), a[index] + k) - a.begin();
        if (y >= 0 && y < n && a[y] == a[index] + k) {
            op2 = f(a, y, index);
        }
        int z = lower_bound(a.begin(), a.end(), a[index] + k + 1) - a.begin();
        if (z >= 0 && z < n && a[z] == a[index] + k + 1) {
            op3 = f(a, z, index);
        }

        return dp[index][prevInd] = op1 || op2 || op3;
    }
    bool canCross(vector<int>& a) {
        if (a[1] != 1) return false;
        memset(dp, -1, sizeof(dp));
        return f(a, 1, 0);
    }
};