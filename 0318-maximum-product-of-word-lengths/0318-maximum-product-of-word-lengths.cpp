class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<unsigned> val;
        for (string& i:words) {
            unsigned res = 0;
            for (char c:i) {
                res = res | (1 << (c - 'a'));
            }
            val.push_back(res);
        }
        int mp = 0;
        for (int i = 0; i < val.size() - 1; ++i) {
            for (int j = i + 1; j < val.size(); ++j) {
                if ((val[i] & val[j]) == 0) {
                    int l1 = words[i].size();
                    int l2 = words[j].size();
                    mp = max(mp, l1 * l2);
                }
            }
        }
        return mp;
    }
};