class Solution {
public:
    int secondHighest(string s) {
        vector<int> ans(10,0);

        for(int i = 0; i < s.size(); i++) {
            int temp= s[i]-'0';
            if( temp >=0 && temp < 10){
                ans[temp]++;
            }
        }
        int count=1;
        for(int i = 9; i >= 0; i--){
            if( ans[i] > 0) {
                if(count == 0){
                    return i;
                }
                count--;
            }
        }

        return -1;

    }
};