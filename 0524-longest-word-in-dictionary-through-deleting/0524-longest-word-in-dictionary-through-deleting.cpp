class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        unordered_map<char, set<int>> mp;
        for(int i=0; i<s.length(); i++){
            mp[s[i]].insert(i);
        }
        string ans = "";
        for(int i=0; i<dictionary.size(); i++){
            int ind = -1;
            bool f = true;
            for(int j=0; j<dictionary[i].size(); j++){
                
                if(mp.find(dictionary[i][j])!=mp.end()){
                    auto it = mp[dictionary[i][j]].upper_bound(ind);
                    if(it==mp[dictionary[i][j]].end()){
                        f = false;
                        break;
                    }else{
                        ind = *it;
                    }
                }else{
                    f = false;
                    break;
                }
            }
            if(!f){
                continue;
            }
            if(ans.length() < dictionary[i].length()){
                ans = dictionary[i];
            }else if(ans.length() == dictionary[i].length()){
                ans = min(ans, dictionary[i]);
            }
        }
        return ans;
    }
};