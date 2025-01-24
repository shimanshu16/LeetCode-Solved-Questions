class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> arr(62, make_pair(0, '\0'));
        for(char c: s) {
            if(islower(c)) {
                arr[c-'a'].second = c;
                arr[c-'a'].first += 1;
            }
            else if(isupper(c)) {
                arr[c-'A'+26].second = c;
                arr[c-'A'+26].first += 1;
            }
            else if(isdigit(c)) {
                arr[c-'0'+52].second = c;
                arr[c-'0'+52].first += 1;
            }
        }
        sort(arr.begin(), arr.end(), greater<>());
        string str = "";
        for(int i=0; i<62; i++) {
            while(arr[i].first--) str += arr[i].second;
        }
        return str;
    }
};