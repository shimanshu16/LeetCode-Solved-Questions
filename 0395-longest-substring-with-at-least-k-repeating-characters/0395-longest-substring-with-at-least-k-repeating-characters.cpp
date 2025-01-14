class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
		
        if(n == 0 or n < k) return 0;
        if(k <= 1) return n;
		
        unordered_map<char,int> countMap;
        for(char c : s) countMap[c]++;
       
        int left =0;
		
        while(left < n && countMap[s[left]] >= k) left++;
        if(left >= n-1) return left;
        int l1 = longestSubstring(s.substr(0,left) ,k);
        
        while(left < n && countMap[s[left]] < k) left++;
        int l2 = left < n ? longestSubstring(s.substr(left),k) : 0;

        return max(l1,l2);
    }
};