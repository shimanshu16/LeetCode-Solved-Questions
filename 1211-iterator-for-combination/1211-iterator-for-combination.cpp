class CombinationIterator {
public:
    vector<string> arr;
    int pos = 0;
    
    void solve(string &s, int len, int pos, string &op){
        if(pos==s.size()){
            if(op.size()==len) arr.push_back(op);
            return;
        }

        op.push_back(s[pos]);
        solve(s,len,pos+1,op);
        op.pop_back();
        solve(s,len,pos+1,op);
    }
    
    CombinationIterator(string characters, int combinationLength) {
        string op = "";
        solve(characters, combinationLength, 0, op);
    }
    
    string next() {
        string ans = arr[pos++];
        return ans;
    }
    
    bool hasNext() {
        return pos<arr.size();
    }
};