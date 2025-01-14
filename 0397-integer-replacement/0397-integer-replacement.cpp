class Solution {
public:
    int integerReplacement(int n) {
        int ans = 0;
        
        while(n > 3){
            ans++;

            if(n%2 == 0) n >>= 1;
            else{

                ans++;

                int t1 = (int64_t(n)+1)>>1, t2 = (n-1)>>1;

                if(t1%2==0 && t2%2==0) n = min(t1, t2);
                else if(t1%2==0) n = t1;
                else n = t2;
            }
        }
        return ans + n-1;
    }
};