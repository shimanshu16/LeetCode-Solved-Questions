class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> result;
        int i = num.size() - 1;

        // Process digits from the end and add with carry (k)
        while (i >= 0 || k > 0) {
            if (i >= 0) {
                k += num[i];  // Add digit to k
                i--;          // Move to the left digit
            }

            result.push_back(k % 10); // Store last digit
            k /= 10;                  // Remove last digit (carry to next)
        }

        // Digits are added in reverse, so reverse the result
        reverse(result.begin(), result.end());
        return result;
    }
};
