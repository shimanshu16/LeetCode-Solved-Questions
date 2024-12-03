class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) {
            return false;
        }

        vector<int> freq1(26, 0), freq2(26, 0);
        vector<int> unique1(26, 0), unique2(26, 0);

        for (char c : word1) {
            freq1[c - 'a']++;
            unique1[c - 'a'] = 1;
        }
        for (char c : word2) {
            freq2[c - 'a']++;
            unique2[c - 'a'] = 1;
        }

        if (unique1 != unique2) {
            return false;
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};