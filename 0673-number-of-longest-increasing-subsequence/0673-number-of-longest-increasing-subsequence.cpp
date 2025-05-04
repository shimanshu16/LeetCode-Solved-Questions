class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();   
        vector<int>size(n, 1);
        vector<int>count(n, 1);
        int maxi =  1;

        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                if(nums[i] > nums[j] && size[i] < 1 + size[j]){
                    size[i] = 1 + size[j];
                    count[i] = count[j];
                }
                else if(nums[i] > nums[j] && size[i] == 1 + size[j]){
                    size[i] = 1 + size[j];
                    count[i] += count[j];
                }
            }
            maxi = max(maxi, size[i]);
        }

        int cnt = 0;
        for(int i = n-1;i >= 0;i--){
            if(size[i] == maxi){
                cnt += count[i];
            }
        }

        return cnt;
    }
};