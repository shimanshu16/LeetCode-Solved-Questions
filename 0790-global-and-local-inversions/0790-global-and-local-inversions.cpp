class Solution {
public:
     Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 2) {
            return 1;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n - 2; i++) {
            maxi = max(maxi, nums[i]);
            if (maxi > nums[i + 2]) {
                return 0;
            }
        }
        return 1;
        
    }
};