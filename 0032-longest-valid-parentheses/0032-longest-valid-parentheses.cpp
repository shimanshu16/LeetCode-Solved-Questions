class Solution {
public:
    int longestValidParentheses(string s) {
        int longest = 0;
        stack<int>st;
        //initially push -1 so that ')' is singly present ,push index into st
        st.push(-1);

        for(int i = 0 ; i< s.size() ; i++){
            if(s[i] == '('){
                st.push(i);
            }
            else
            st.pop(); //at ')' pop
             if(!st.empty()){  //after popping -1 is present, find longest
                longest = max(longest,i-st.top()); 
            }
            else
            st.push(i); //stack is empty ,push ')' || '('
            
        }
      return longest;
    }
};