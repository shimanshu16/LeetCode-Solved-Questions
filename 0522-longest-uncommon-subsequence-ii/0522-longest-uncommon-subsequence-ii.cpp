class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        auto IsSubsequence = [](const string& base, const string& subseq) -> bool {
            int base_i = 0;
            for (int i = 0 ; i < subseq.size() ; ++i) {
                while (base_i < base.size() && base[base_i] != subseq[i]) {
                    ++base_i;
                }
                if (base_i == base.size()) {
                    return false;
                }
                ++base_i;
            }
            return true;
        };
        for (int i = 0 ; i < strs.size() ; ++i) {
            bool broken = false;
            for (int j = 0 ; j < strs.size() ; ++j) {
                if (i == j) continue;
                if (IsSubsequence(strs[j], strs[i])) {
                    broken = true;
                    break;
                }
            }
            if (!broken) {
                res = max(res, static_cast<int>(strs[i].size()));
            }
        }
        return res; 
    }
};