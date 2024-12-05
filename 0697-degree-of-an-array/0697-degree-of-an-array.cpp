class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        int degree = 0;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if (first.find(nums[i]) == first.end()) {
                first[nums[i]] = i;
            }
            last[nums[i]] = i;

            degree = max(degree, freq[nums[i]]);
        }

        int minLength = nums.size();
        for (auto& [num, count] : freq) {
            if (count == degree) {
                minLength = min(minLength, last[num] - first[num] + 1);
            }
        }

        return minLength;

    }
};