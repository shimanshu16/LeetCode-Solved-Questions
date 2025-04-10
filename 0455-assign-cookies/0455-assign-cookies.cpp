class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size(),n=s.size(),child=0,cookie=0,childcount=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(child<m && cookie<n){
            
            if(s[cookie++]>=g[child]){
                childcount++;
                child++;
            }
        }
        return childcount;
    }
};