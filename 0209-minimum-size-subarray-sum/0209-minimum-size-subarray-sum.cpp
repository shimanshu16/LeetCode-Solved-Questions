class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int right = 0;
        int minsub =INT_MAX ;
        int sum = 0;
        while(right< nums.size()){
            sum = sum+nums[right];
            while(sum>=target){
                minsub = min(minsub, right-left+1);
                sum = sum - nums[left];
                left++;      
            }
            right++;
        }
       if(minsub == INT_MAX)
            return 0;
        else
            return minsub;
    }
};