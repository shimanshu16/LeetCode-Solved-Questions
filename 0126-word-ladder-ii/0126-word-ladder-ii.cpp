class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_map<string, int> dist;
        unordered_map<string,vector<string>> parent;
        
   
        queue<string> q;
        q.push(beginWord);
        
        for(auto it: wordList)
        {
            dist[it] = INT_MAX;
        }
        dist[beginWord] = 0; 

        while(!q.empty()){

            string word =q.front();q.pop();

            for(int i=0;i<word.size();i++){                
                for(char c ='a';c<='z';c++){                    
                    string nxtword = word;
                    nxtword[i]=c;  

                    if(dist.find(nxtword)!=dist.end()){ 
                        
                        if(dist[nxtword]> dist[word]+1){  
                            dist[nxtword] = dist[word]+1;
                            q.push(nxtword);
                            parent[nxtword].clear(); 
                            parent[nxtword].push_back(word); 
                        }

                        else if(dist[nxtword]== dist[word]+1){ 
                            parent[nxtword].push_back(word); 
                        }

                    }
                }
            }
        }

        vector<vector<string>> res;
        vector<string> path;
        path.push_back(endWord);
        backtrack(parent,endWord,res,path,beginWord);

        return res;

    }

    void backtrack(unordered_map<string,vector<string>>& parent,string node, vector<vector<string>>& res,vector<string>& path,string beginWord){

        if(node==beginWord){ 
            vector<string> a = path;
            reverse(a.begin(),a.end());
            res.push_back(a);

            return;
        }

        for(string& p : parent[node]){
            path.push_back(p);
            backtrack(parent,p,res,path,beginWord);
            path.pop_back();
        }
    }
};