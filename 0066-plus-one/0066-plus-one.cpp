class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>sum;
        int Sum = 0;
        int carry = 1;
        for(int i=digits.size()-1;i>=0;i--){
            Sum=0;
            Sum = digits[i]+carry;
            sum.push_back(Sum%10);
            carry = Sum/10;
        }
        if(carry == 1){
            sum.push_back(1);
        }
        reverse(sum.begin(),sum.end());
        return sum;
    }
};