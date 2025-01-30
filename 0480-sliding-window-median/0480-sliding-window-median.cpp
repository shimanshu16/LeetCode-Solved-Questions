class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        unordered_map<int, int> outgoingNum;
        priority_queue<int> smallList;
        priority_queue<int, vector<int>, greater<int>> largeList;

        for (int i = 0; i < k; i++) {
            smallList.push(nums[i]);
        }

        for (int i = 0; k && i < k / 2; i++) {
            largeList.push(smallList.top());
            smallList.pop();
        }

        int balance = 0;
        int i = k;

        while (true) {
            if (k % 2 == 1) {
                medians.push_back(smallList.top());
            } else {
                medians.push_back(
                    ((long long)smallList.top() + (long long)largeList.top()) *
                    0.5);
            }

            if (i >= nums.size()) {
                break;
            }

            int outNum = nums[i - k];
            int inNum = nums[i];
            i++;

            if (outNum <= smallList.top()) {
                balance -= 1;
            } else {
                balance += 1;
            }

            outgoingNum[outNum]++;

            if (!smallList.empty() && inNum <= smallList.top()) {
                balance += 1;
                smallList.push(inNum);
            } else {
                balance -= 1;
                largeList.push(inNum);
            }

            if (balance < 0) {
                smallList.push(largeList.top());
                largeList.pop();
            } else if (balance > 0) {
                largeList.push(smallList.top());
                smallList.pop();
            }

            balance = 0;

            while (!smallList.empty() && outgoingNum[smallList.top()]) {
                outgoingNum[smallList.top()]--;
                smallList.pop();
            }

            while (!largeList.empty() && outgoingNum[largeList.top()]) {
                outgoingNum[largeList.top()]--;
                largeList.pop();
            }
        }

        return medians;
    }
};