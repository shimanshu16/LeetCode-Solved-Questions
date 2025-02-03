class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        bool flag = false;
        if(num < 0) {
            flag = true;
            num *= -1;
        }
        while(num >= 7) {
            char ch = (num%7)+'0';
            ans = ch + ans;
            num /= 7;
        }
        char ch = num +'0';
        ans = ch + ans;
        if(flag)
            ans = "-" + ans;
        return ans;
    }
};