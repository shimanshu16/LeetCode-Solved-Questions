class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;  
        long long ans = 0, pairs = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            int val = nums[right];

            pairs += freq[val];
            freq[val]++;

            while (pairs >= k) {
                ans += nums.size() - right;
                int out = nums[left++];
                freq[out]--;
                pairs -= freq[out];
            }
        }
        return ans;
    }
};