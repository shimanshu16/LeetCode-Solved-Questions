class Solution {
public:

    string reverseStr(string s1, int k) {

       for (int i = 0; i<s1.size(); i += 2*k) {
    
            int s = i;
            int e = min(s + k - 1, (int)s1.size()-1);
            while (s < e) {
                swap(s1[s], s1[e]);
                s++;
                e--;
            }
        }

        return s1;
    }
};