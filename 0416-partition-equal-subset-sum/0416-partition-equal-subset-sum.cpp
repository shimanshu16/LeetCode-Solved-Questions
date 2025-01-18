class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) return false;

        unordered_map<int, bool> dp;
        dp[0] = true;
        int target = sum / 2;

        for (int i = nums.size() - 1; i >= 0; i--) {
            unordered_map<int, bool> temp;
            for (auto t : dp) {
                if (t.first + nums[i] == target) return true;
                if (!temp[t.first + nums[i]]) temp[t.first + nums[i]] = true;
                temp[t.first] = true;
            }
            dp = temp;
        }
        
        if (dp[target]) return true;
        return false;
    }
};