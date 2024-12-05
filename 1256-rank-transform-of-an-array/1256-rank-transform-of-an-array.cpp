class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());

        unordered_map<int, int> rank;
        int currentRank = 1;

        for (int num : sortedArr) {
            if (rank.find(num) == rank.end()) {
                rank[num] = currentRank++;
            }
        }

        vector<int> result;
        for (int num : arr) {
            result.push_back(rank[num]);
        }

        return result;

    }
};