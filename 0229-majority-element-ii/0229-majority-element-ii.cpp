class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
            map<int, int>m; vector<int>ans;
        for(auto i:nums) m[i]++;
        for(auto i: m){
            if(i.second > floor(nums.size()/3)){
                ans.push_back(i.first);
            }
        }
        return ans; 
    }
};