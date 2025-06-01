class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //long long lenge
        long long first = LLONG_MIN;          //largest
        long long second = LLONG_MIN;          //second largest
        long long third = LLONG_MIN;          //third largest

        //loop chlayenge each number pr array main
        for(int num : nums){       //initialize
            if (num == first || num == second || num ==third)          //condition
            continue;
            // update the top three numbers
            if (num > first){
                third = second;
                second = first;
                first = num;
            } else if (num > second){
                third = second;
                second = num;
            } else if ( num > third){
                third = num;
            }
        }
        return third == LLONG_MIN ? first : third;
    }
};