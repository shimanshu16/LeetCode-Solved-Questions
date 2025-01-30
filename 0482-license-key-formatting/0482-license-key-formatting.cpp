class Solution {
public:
    void reverseStr(string& str)
    {
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }
    
    string licenseKeyFormatting(string s, int k) {
        string result = "";
        int counter = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] != '-') 
            {
                result += toupper(s[i]);
                counter++;
                if(counter == k){
                    result += '-';
                    counter = 0;
                }
            }
        }
        reverseStr(result);
        if(result[0] == '-') return result.substr(1);
        return result;
    }
};