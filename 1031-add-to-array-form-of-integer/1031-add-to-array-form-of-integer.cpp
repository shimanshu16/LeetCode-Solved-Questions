class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result; // This will store the final answer
        int i = num.size() - 1; // Start from the last digit of the array
         //loop chlayenge k ka jisme apn ko loop tab tak chlana hai jab tak k ki value 0 naa ho jaaye with the heklp of mudulo
         while( i>=0 || k >0){
            if(i >= 0){
                k += num[i]; //Add the current digit from array to k
                i--; //Move to previous digit in the array if we find zero or done with previous adding
            }
            // k % 10 krenge aisa krke ek ek digit nikal kr add krte jaayenge aur piche jaaty jaayenge
            result.push_back(k%10);
            // update k by removing last digit (carry wale ke liye)
            k = k/10;
         }
            //we add digits from last to first,so now print result means apn yahan pr result pr focus krenge jo apn ne last to first say add kiya hai
            reverse(result.begin(), result.end());
            return result;
         
    }
};