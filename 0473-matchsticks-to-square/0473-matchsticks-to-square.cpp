class Solution {
public:

    bool helper(vector<int>& nums , int& target , int sum , int k , int idx , vector<bool>& v){

        if (k == 0) return true;  
        
        if (sum == 0){      
            return helper(nums, target, target, k - 1, 0, v);
        }

        unordered_set<int> s;

        for(int i = idx; i < nums.size(); i++){

            if (v[i] || s.count(nums[i]) || sum - nums[i] < 0) continue;

            s.insert(nums[i]);
            v[i] = true;     

            if(helper(nums , target , sum - nums[i] , k , i + 1 , v)) return true;

            v[i] = false;   

        }

        return false;
    }

    bool makesquare(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0); 

        if (sum % 4 != 0) return false;

        int target = sum / 4;

        sort(nums.begin(), nums.end());

        vector<bool> v(nums.size(), false);

        return helper(nums, target, target, 4, 0, v);
    }
};