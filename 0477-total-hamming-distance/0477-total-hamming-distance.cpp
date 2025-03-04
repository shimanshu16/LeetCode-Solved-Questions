class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int xOR = nums[i]^nums[j];
                ans += __builtin_popcount(xOR);
            }
        }
        return ans;
    }
};