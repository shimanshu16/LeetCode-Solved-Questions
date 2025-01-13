class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.size(),m=t.size();
        
        
        int start2=0;
        vector<int>count(26,0);
        while(start2!=m){
            if(start2<n){
                count[s[start2]-'a']--;
            }
            count[t[start2]-'a']++;
            start2++;
            
        }
        for(int i=0;i<26;i++){
            if(count[i])
            return (i+'a');
        }
        return 'a';
        
    }
};