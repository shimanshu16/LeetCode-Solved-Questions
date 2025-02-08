class Solution {
public:
    bool detectCapitalUse(string word) {
        if(isupper(word[0])){
            int a=0,b=0;
           for(int i=1;i<word.size();i++){
            if(isupper(word[i])){
                a=1;
            }
            else {
                b=1;
            }
           }
           if(a==1 && b==1) return false;
           else return true;
        }
        else{
            bool a=true;
        for(int i=1;i<word.size();i++){
            if(isupper(word[i])) {
                a=false;;
                break;
            }
        }
        return a;
        }
    }
};