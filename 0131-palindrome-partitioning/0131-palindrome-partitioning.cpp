class Solution {
public:
    bool ispalindrome(const string& s, int start, int end)
    {
        while( start < end)
        {
            if( s[start] != s[end])
                return false;
            start++;
            --end;
        }
        return true;
    }

    void backtracking(int index, vector<string> &palindrome, string& s,                 vector<vector<string>>& res )
    {
        if( index == s.size())
        {
            res.push_back(palindrome);
            return;
        }

        for( int i = index; i < s.size(); i++)
        {
            if( ispalindrome(s, index, i))
            {
                palindrome.push_back(s.substr(index, i-index+1));
                backtracking(i+1, palindrome, s, res);
                palindrome.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        if(s.empty())
            return result;

        vector<string> palindrome;
        int index = 0;
        backtracking(index, palindrome, s, result);
        return result;    
    }
};