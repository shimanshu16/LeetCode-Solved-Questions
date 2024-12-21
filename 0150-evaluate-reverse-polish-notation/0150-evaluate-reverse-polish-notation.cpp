class Solution {
public:
    int top;
    int f(vector<string>& tokens){
        string s=tokens[top--];
        if (isdigit(s[0]) || s.size()>1)
            return stoi(s);
        int n2=f(tokens);
        int n1=f(tokens);
        
        switch(s[0]){
            case '+': return n1+n2; 
            case '-': return n1-n2; 
            case '*': return n1*n2; 
            case '/': return n1/n2; 
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {  
        top=tokens.size()-1;     
        return f(tokens);
    }
};