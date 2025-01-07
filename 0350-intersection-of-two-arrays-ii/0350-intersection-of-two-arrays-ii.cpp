class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        for (int x : nums1) {
            map[x]++;
        }
        vector<int> res;
        for (int x : nums2) {
            if (map[x] > 0) {
                res.push_back(x);
                map[x]--;
            }
        }
        return res;
    }
};