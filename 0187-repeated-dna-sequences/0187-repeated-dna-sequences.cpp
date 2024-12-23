class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int>m;
        vector<string> vec;
        string sub;
        if(s.size()<10)
        {
            return vec;
        }
         for(int i=0;i<=s.size()-10;i++){
         sub=s.substr(i,10);
         if(m.find(sub)!=m.end()){
            m[sub]++;
         }
         else{
            m.insert(make_pair(sub,1));
         }

        }
        map<string,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            if(it->second>1){
                vec.push_back(it->first);
            }
        }
      return vec;  
    }
};