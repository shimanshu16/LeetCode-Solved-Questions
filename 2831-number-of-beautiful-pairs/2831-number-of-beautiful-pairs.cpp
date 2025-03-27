class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                string str1 = to_string(nums[i]), str2 = to_string(nums[j]);
                if (gcd(str1[0] - '0', str2[str2.length() - 1] - '0') == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};