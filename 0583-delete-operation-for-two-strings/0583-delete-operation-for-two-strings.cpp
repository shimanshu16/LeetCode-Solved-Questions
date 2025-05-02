
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1 = word1.size(),w2 = word2.size(); 
        vector<int>prev(w2+1,0);
        vector<int>curr(w2+1,0);
            for(int i = 1; i <= w1; i++){
                for(int j = 1; j <= w2; j++){
                    if(word1[i-1] == word2[j-1]){
                        curr[j] = 1 + prev[j-1];
                    }else{
                        curr[j] = max(prev[j],curr[j-1]);
                    }
                }
                prev = curr; 
            }
        int n = prev[w2]; 
        return w1+w2 - 2*n;
    }
};