typedef long long ll;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        ll res = 0;
        int l = n - 1, r = n - 1;
        for (int i = 0; i < n; i++) {
            int low = lower - nums[i];
            int upp = upper - nums[i];
            while (l >= 0 && nums[l] >= low) l--;
            while (r >= 0 && nums[r] > upp) r--;
            res += (r - l) - (l < i && i <= r);
        }
        return res / 2;
    }
};