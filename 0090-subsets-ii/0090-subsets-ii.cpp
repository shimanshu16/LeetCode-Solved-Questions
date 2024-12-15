class Solution {
public:
    void solve(vector<int>& nums, vector<int> &output, set<vector<int>> &st, int i) {
        
        if(i >= nums.size()) {
            st.insert(output);
            return;
        }

        output.push_back(nums[i]);
        solve(nums, output, st, i + 1);
        output.pop_back();

        solve(nums, output, st, i + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> output;
        int i = 0;
        sort(nums.begin(), nums.end());
        solve(nums, output, st, i);
        for(auto it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};