class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
    int main(){
        vector<int> nums = {5,2,3,1};
        vector<int> sortedArray = sortArray(nums);

        for(int num : sortedArray) {
            cout << num << " ,";
        }
        return 0;
    }
};