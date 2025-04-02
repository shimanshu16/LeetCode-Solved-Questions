class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        const int n=nums.size();
        long long L=nums[0], maxD=L-nums[1], ans=max(0LL, maxD*nums[2]);
        for(int k=3; k<n; k++){
            L=max(L, (long long)nums[k-2]);
            maxD=max(maxD, L-nums[k-1]);
            ans=max(ans, maxD*nums[k]);
        }
        return ans;
    }
};