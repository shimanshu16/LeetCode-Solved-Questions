class Solution {
public:
    int dp[21][21];
    int helper(int start,int end,vector<int> &nums){
        if(end<start)return 0;
        if(dp[start][end]!=-1)return dp[start][end];
        return dp[start][end]=max(nums[start]-helper(start+1,end,nums),nums[end]-helper(start,end-1,nums));
    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return helper(0,n-1,nums)>=0;
    }
};