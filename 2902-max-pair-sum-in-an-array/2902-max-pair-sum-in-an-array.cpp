class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        
        auto getMaxDigit = [](int x) {
            int maxDigit = 0;
            while (x > 0) {
                maxDigit = max(maxDigit, x % 10);
                x /= 10;
            }
            return maxDigit;
        };
    
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (getMaxDigit(nums[i]) == getMaxDigit(nums[j])) {
                    ans = max(ans, nums[i] + nums[j]);
                }
            }
        }
        
        return ans;
 
    }
};