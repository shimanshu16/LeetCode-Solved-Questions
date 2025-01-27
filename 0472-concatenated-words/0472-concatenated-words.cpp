class Solution {
public:

    unordered_set<string>dict;
    vector<string>finalAns;

    vector<vector<int>>dp;
    
    bool solve(int i, int j, vector<string>& words){
        if(j == words[i].length()) return true;
        if(dp[i][j] != -1) return dp[i][j];

        bool res = false;

        string temp = "";
        for(int k = j; k<words[i].length(); k++){

            temp.push_back(words[i][k]);
            if(dict.find(temp) != dict.end() && temp != words[i]){

                res = res || solve(i, k+1, words);
            }
        }

        return dp[i][j] = res;

    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        for(auto word: words) dict.insert(word);
        dp.resize(words.size()+1, vector<int>(10001, -1));

        for(int a = 0; a<words.size(); a++){
            
            bool isConc = solve(a, 0, words);
            if(isConc) finalAns.push_back(words[a]);
        }

        return finalAns;
    }
};