class Solution {
public:
    static vector<int> minOperations(string& boxes) {
        const int n = boxes.size();
        vector<int> ans(n, 0);
        vector<int> P;

        for (int i = 0; i < n; i++) {
            if (boxes[i]=='1') {
                P.push_back(i);
                ans[0]+=i; 
            }
        }

        int pz=P.size(), L=0, R=pz;

        for (int i=1, j= 0; i<n; i++) {
            if (j<pz && i>P[j]) {
                L++;
                R--;
                j++;
            }
            ans[i]=ans[i-1]+L-R;
        }

        return ans;
    }
};