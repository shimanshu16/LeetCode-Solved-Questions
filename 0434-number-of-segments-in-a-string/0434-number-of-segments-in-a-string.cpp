class Solution {
public:
    int countSegments(string s) {
    int n=s.size();
    char prev='\0';
    int cnt=0;
    for(int i=0;i<n;i++){
        char ch=s[i];
       if (!isspace(ch) && (prev == '\0' || isspace(prev))) {
                cnt++; 
            }
        prev=ch;
        
    }
return cnt;
    }
};