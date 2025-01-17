class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size(),cnt=0,ans=0;
        if(n<3) return 0;
        vector<int>dp(n,0);
        for(int i=1;i<n-1;i++){
            if(nums[i]-nums[i-1]==nums[i+1]-nums[i]) dp[i]=1;
        }
        for(int i=1;i<n;i++){
            if(dp[i]==0){
                ans+=cnt*(cnt+1)/2;
                cnt=0;
            }
            else cnt++;
        }
        return ans;
    }
};