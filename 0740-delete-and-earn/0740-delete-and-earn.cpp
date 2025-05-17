class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);

        for (int num : nums)
            points[num] += num;

        int take = 0, skip = 0;

        for (int i = 0; i <= maxVal; i++) {
            int take_i = skip + points[i];
            int skip_i = max(skip, take);
            take = take_i;
            skip = skip_i;
        }

        return max(take, skip);
    }
};
